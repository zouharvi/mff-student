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
const G_ABSTR: &str = "./data/hulth2003/*.abstr";
const LENGTH_POWER: f32 = 1.2;
const DUPLICITY_SCORE: f32 = 0.5;

fn main() {
    println!("Opening stopwords from '{}'", F_STOPWORDS);
    let sws_raw: String = fs::read_to_string(F_STOPWORDS).expect("The file could not be opened.");
    let sws: HashSet<&str> = HashSet::from_iter(sws_raw.lines());
    println!("Reading all from '{}'", G_ABSTR);
    let data = DocAll::read_all(&sws, G_ABSTR);

    for entry in glob(G_ABSTR).expect("Failed to read glob pattern") {
        match entry {
            Ok(path) => {
                let mut uncontr_path = PathBuf::from(&path);
                uncontr_path.set_extension("uncontr");
                process_abstr(
                    &data,
                    &sws,
                    path.as_os_str().to_str().unwrap(),
                    uncontr_path.as_os_str().to_str().unwrap(),
                );
            }
            Err(e) => println!("{:?}", e),
        }
    }
}

fn process_abstr(data: &DocAll, sws: &HashSet<&str>, f_abstr: &str, f_uncontr: &str) {
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

    if true {
        println!("Score  Keyword {}", f_abstr);
        for n in 1..15 {
            if n >= keyword_vec.len() {
                break;
            }
            let (key, val) = keyword_vec.get(n).unwrap();
            if uncontr.contains(*key) {
                println!("* {:.3}: {}", val, key);
            } else {
                println!("  {:.3}: {}", val, key);
            }
        }
    }
}
