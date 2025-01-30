use crate::doc_reader::DocAll;
use lazy_static::lazy_static;
use regex::Regex;
use std::collections::HashSet;
use std::fmt;

pub struct Candidate {
    // the original candidate string
    pub raw: String,
    // number of words in the raw string
    sub_count: u8,
    // frequency in the whole document
    count_doc: u16,
    // frequency in all documents
    count_all: u16,
    // total words in the document
    word_count_doc: u32,
    // total words
    word_count_all: u32,
    // Probability of being a good keyword
    _prob: f32,
}

impl Candidate {
    pub fn new(words: Vec<String>, doc_name: &str, doc_all: &DocAll) -> Candidate {
        let word_count = words.len();
        let raw = words.join(" ");

        let count_pw_all = words
            .iter()
            .map(|word| doc_all.map_word_count.get(word).unwrap_or(&0))
            .sum::<u32>() as f32;
        let count_doc = doc_all
            .map_doc_raw
            .get(doc_name)
            .unwrap_or(&"".to_owned())
            .matches(raw.as_str())
            .count();

        Candidate {
            raw,
            sub_count: word_count as u8,
            count_doc: count_doc as u16,
            count_all: count_pw_all as u16,
            word_count_doc: *doc_all.map_doc_size.get(doc_name).unwrap(),
            word_count_all: doc_all.count_words as u32,
            _prob: 0.0,
        }
    }

    pub fn vectorize<T>(&self) -> Vec<f32> {
        vec![
            self.sub_count as f32,
            self.count_doc as f32,
            self.count_all as f32,
            self.word_count_doc as f32,
            self.word_count_all as f32,
        ]
    }

    pub fn create_candidates<'a>(
        words: &[&'a str],
        doc_name: &str,
        sws: &HashSet<&str>,
        doc_all: &DocAll,
    ) -> Vec<Candidate> {
        let mut buffer: Vec<String> = Vec::new();
        let mut candidates: Vec<Candidate> = Vec::new();
        lazy_static! {
            static ref R_UPPERCASE: Regex = Regex::new(r"\p{Lu}.+").unwrap();
        }

        for word in words {
            if sws.contains(&word.to_lowercase().as_str()) {
                if !buffer.is_empty() {
                    candidates.push(Candidate::new(buffer, doc_name, doc_all));
                    buffer = Vec::new();
                }
            } else if R_UPPERCASE.is_match(word) {
                if !buffer.is_empty() {
                    candidates.push(Candidate::new(buffer, doc_name, doc_all));
                    buffer = Vec::new();
                }
                buffer.push(word.to_lowercase());
            } else {
                buffer.push(word.to_lowercase());
            }
        }
        candidates
    }

    pub fn gold_keywords(
        keywords: &[String],
        doc_name: &str,
        doc_all: &DocAll,
    ) -> Vec<Candidate> {
        let mut candidates: Vec<Candidate> = Vec::new();
        lazy_static! {
            static ref R_UPPERCASE: Regex = Regex::new(r"\p{Lu}.+").unwrap();
        }

        for keyword in keywords {
            let count_pw_all = keyword
                .split_ascii_whitespace()
                .collect::<Vec<&str>>()
                .iter()
                .map(|word| doc_all.map_word_count.get(*word).unwrap_or(&0))
                .sum::<u32>() as f32;

            let count_doc = doc_all
                .map_doc_raw
                .get(doc_name)
                .unwrap_or(&"".to_owned())
                .matches(keyword.as_str())
                .count();

            candidates.push(Candidate {
                raw: keyword.to_owned(),
                sub_count: keyword.split_ascii_whitespace().count() as u8,
                count_doc: count_doc as u16,
                count_all: count_pw_all as u16,
                word_count_doc: *doc_all.map_doc_size.get(doc_name).unwrap(),
                word_count_all: doc_all.count_words as u32,
                _prob: 1.0,
            });
        }

        candidates
    }
}

impl fmt::Display for Candidate {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{} {:?}", self.raw, self.vectorize::<Vec<f32>>())
    }
}
