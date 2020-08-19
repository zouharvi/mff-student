use crate::candidate::Candidate;
use glob::glob;
use lazy_static::lazy_static;
use regex::Regex;
use std::collections::HashSet;
use std::fs;
use std::iter::FromIterator;
use std::path::PathBuf;

mod candidate;
mod doc_reader;

use doc_reader::DocAll;

pub mod options {
    pub const F_STOPWORDS: &str = "./data/stopwords.txt";
    pub const G_ABSTR: &str = "./data/hulth2003_src/*.abstr";
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

    for entry in glob(options::G_ABSTR).unwrap() {
        match entry {
            Ok(path) => {
                let mut uncontr_path = PathBuf::from(&path);
                uncontr_path.set_extension("uncontr");
                process_abstr(
                    &data,
                    &sws,
                    uncontr_path.file_stem().unwrap().to_str().unwrap(),
                    path.to_str().unwrap(),
                    uncontr_path.to_str().unwrap(),
                )
            }
            Err(_) => (),
        }
    }
}

fn process_abstr(
    data: &DocAll,
    sws: &HashSet<&str>,
    doc_name: &str,
    f_abstr: &str,
    f_uncontr: &str,
) {
    lazy_static! {
        static ref R_NOT_WORD: Regex = Regex::new(r"[^\pL]+").unwrap();
        static ref R_GARBAGE: Regex = Regex::new(r"[\n\t\r;]").unwrap();
        static ref R_SPACE: Regex = Regex::new(r"^\s*$").unwrap();
    }
    let doc_raw: String = fs::read_to_string(f_abstr).unwrap();
    let doc_words: Vec<&str> = R_NOT_WORD.split(&doc_raw).collect();

    // GOLD
    let uncontr = R_GARBAGE
        .split(fs::read_to_string(f_uncontr).unwrap().as_str())
        .filter(|x| !R_SPACE.is_match(x))
        .map(|x| x.to_lowercase().trim_matches(' ').to_owned())
        .collect::<Vec<String>>();
    let uncontr_set: HashSet<&str> = HashSet::from_iter(uncontr.iter().map(|x| x.as_str()));

    let candidates = candidate::Candidate::create_candidates(&doc_words, doc_name, &sws, data);
    let gold_keywords = candidate::Candidate::gold_keywords(&uncontr, doc_name, data);

    let candidates = candidates.iter().filter(|x| !uncontr_set.contains(x.raw.as_str())).collect::<Vec<&Candidate>>();

    // for candidate in &candidates {
    //     println!("{}", candidate);
    // }
    for candidate in &gold_keywords {
        println!("{}", candidate);
    }
}
