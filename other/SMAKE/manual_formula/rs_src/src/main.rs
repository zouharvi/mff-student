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

pub mod options {
    pub const F_STOPWORDS: &str = "./data/stopwords.txt";
    pub const G_ABSTR: &str = "./data/hulth2003_all/*.abstr";
    pub const PRINT_RESULTS: bool = false;
    pub const CONSIDERED_RESULTS: usize = 15;
    pub const LENGTH_POWER: f32 = -1.5;
    pub const DUPLICITY_SCORE: f32 = 0.9;
}

fn main() {
    println!("Opening stopwords from '{}'", options::F_STOPWORDS);
    let sws_raw: String = fs::read_to_string(options::F_STOPWORDS).unwrap();
    let sws: HashSet<&str> = HashSet::from_iter(sws_raw.lines());
    println!("Reading all from '{}'", options::G_ABSTR);
    let data = DocAll::read_all(&sws, options::G_ABSTR);

    let hits: u32 = glob(options::G_ABSTR)
        .unwrap()
        .map(|entry| match entry {
            Ok(path) => {
                let mut uncontr_path = PathBuf::from(&path);
                uncontr_path.set_extension("uncontr");
                process_abstr(
                    &data,
                    &sws,
                    path.as_os_str().to_str().unwrap(),
                    uncontr_path.as_os_str().to_str().unwrap(),
                )
            }
            Err(_) => 0,
        })
        .sum();
    println!("Hit ratio: {}", (hits as f32) / (data.no_documents as f32));
}

fn process_abstr(data: &DocAll, sws: &HashSet<&str>, f_abstr: &str, f_uncontr: &str) -> u32 {
    lazy_static! {
        static ref R_NOT_WORD: Regex = Regex::new(r"[^\pL]+").unwrap();
        static ref R_GARBAGE: Regex = Regex::new(r"[\n\t\r;]").unwrap();
        static ref R_SPACE: Regex = Regex::new(r"^\s*$").unwrap();
    }
    let doc_raw: String = fs::read_to_string(f_abstr).unwrap();
    let doc_words: Vec<&str> = R_NOT_WORD.split(&doc_raw).collect();

    let uncontr: HashSet<String> = R_GARBAGE
        .split(fs::read_to_string(f_uncontr).unwrap().as_str())
        .filter(|x| !R_SPACE.is_match(x))
        .map(|x| x.to_lowercase().trim_matches(' ').to_string())
        .collect::<HashSet<String>>();

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
            true => {
                sum / f32::powf(candidate.len() as f32, options::LENGTH_POWER)
                    + options::DUPLICITY_SCORE
            }
            false => sum / f32::powf(candidate.len() as f32, options::LENGTH_POWER),
        };
        keywords.insert(key, score);
    }
    let mut keyword_vec: Vec<(&str, &f32)> =
        keywords.iter().map(|(k, v)| (k.as_str(), v)).collect();
    keyword_vec.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap());
    let mut hits = 0;
    if options::PRINT_RESULTS {
        println!("Score  Keyword {}", f_abstr);
    }
    for n in 0..options::CONSIDERED_RESULTS {
        if n >= keyword_vec.len() {
            break;
        }
        let (key, val) = keyword_vec.get(n).unwrap();
        if uncontr.contains(*key) {
            if options::PRINT_RESULTS {
                println!("* {:.3}: {}", val, key);
            }
            hits += 1;
        } else {
            if options::PRINT_RESULTS {
                println!("  {:.3}: {}", val, key);
            }
        }
    }
    hits
}
