use glob::glob;
use lazy_static::lazy_static;
use regex::Regex;
use std::collections::{HashMap, HashSet};
use std::f32;
use std::fs;
use std::iter::FromIterator;
use std::path::PathBuf;

mod data_utils;
mod doc_reader;

use doc_reader::DocAll;

const F_STOPWORDS: &str = "./data/stopwords.txt";
const G_ABSTR: &str = "./data/hulth2003_all/*.abstr";
const PRINT_RESULTS: bool = false;
const CONSIDERED_RESULTS: usize = 15;
const LENGTH_POWER: f32 = 0.16;
const DUPLICITY_SCORE: f32 = -0.8;

fn main() {
    println!("Opening stopwords from '{}'", F_STOPWORDS);
    let sws_raw: String = fs::read_to_string(F_STOPWORDS).unwrap();
    let sws: HashSet<&str> = HashSet::from_iter(sws_raw.lines());
    println!("Reading all from '{}'", G_ABSTR);
    let data = DocAll::read_all(&sws, G_ABSTR);

    let mut hits = 0;
    let mut doc_count = 0;
    for entry in glob(G_ABSTR).unwrap() {
        match entry {
            Ok(path) => {
                doc_count += 1;
                let mut uncontr_path = PathBuf::from(&path);
                uncontr_path.set_extension("uncontr");
                hits += process_abstr(
                    &data,
                    &sws,
                    path.as_os_str().to_str().unwrap(),
                    uncontr_path.as_os_str().to_str().unwrap(),
                );
            }
            Err(e) => println!("{:?}", e),
        }
    }
    println!("Hit ratio: {}", (hits as f32) / (doc_count as f32));
}

fn process_abstr(data: &DocAll, sws: &HashSet<&str>, f_abstr: &str, f_uncontr: &str) -> u32 {
    lazy_static! {
        static ref R_NOT_WORD: Regex = Regex::new(r"[^\pL]+").unwrap();
    }
    let doc_raw: String = fs::read_to_string(f_abstr).unwrap();
    let doc_words: Vec<&str> = R_NOT_WORD.split(&doc_raw).collect();

    let uncontr_raw: String = fs::read_to_string(f_uncontr)
        .unwrap()
        .replace(&['\n', '\t', '\r'][..], "");
    let uncontr: HashSet<&str> = HashSet::from_iter(uncontr_raw.split("; "));

    let candidates = data_utils::create_candidates(doc_words, &sws);
    let (frqs, degs) = data_utils::compute_frq_deg(&candidates);

    let mut rat: HashMap<&str, f32> = HashMap::new();
    for (key, f_val) in frqs {
        let d_val = *degs.get(&key).unwrap() as f32;
        rat.insert(key, d_val / (f_val as f32));
    }

    let mut keywords: HashMap<String, f32> = HashMap::new();
    for candidate in &candidates {
        let key: String = candidate.join(" ");
        let sum: f32 = candidate
            .iter()
            .map(|word| rat.get(word.as_str()).unwrap() * data.term_idf(word))
            .sum();
        let score = match keywords.contains_key(key.as_str()) {
            true => sum / f32::powf(candidate.len() as f32, LENGTH_POWER),
            false => sum / f32::powf(candidate.len() as f32, LENGTH_POWER) + DUPLICITY_SCORE,
        };
        keywords.insert(key, score);
    }

    let mut keyword_vec: Vec<(&str, &f32)> =
        keywords.iter().map(|(k, v)| (k.as_str(), v)).collect();
    keyword_vec.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap());

    let mut hits = 0;
    if PRINT_RESULTS {
        println!("Score  Keyword {}", f_abstr);
    }
    for n in 0..CONSIDERED_RESULTS {
        if n >= keyword_vec.len() {
            break;
        }
        let (key, val) = keyword_vec.get(n).unwrap();
        if uncontr.contains(*key) {
            if PRINT_RESULTS {
                println!("* {:.3}: {}", val, key);
            }
            hits += 1;
        } else {
            if PRINT_RESULTS {
                println!("  {:.3}: {}", val, key);
            }
        }
    }
    hits
}
