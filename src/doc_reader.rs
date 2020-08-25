use glob::glob;
use regex::Regex;
use std::collections::{HashMap, HashSet};
use std::fs;

pub struct DocAll {
    pub map_word_count: HashMap<String, u32>,
    pub map_doc_raw: HashMap<String, String>,
    pub map_doc_size: HashMap<String, u32>,
    pub count_docs: u32,
    pub count_words: u32,
}

impl DocAll {
    pub fn read_all(sws: &HashSet<&str>, g_abstr: &str) -> DocAll {
        let r_not_word = Regex::new(r"[^\pL]").unwrap();
        let mut map_word_count = HashMap::<String, u32>::new();
        let mut map_doc_raw = HashMap::<String, String>::new();
        let mut map_doc_size = HashMap::<String, u32>::new();
        let mut count_docs = 0;
        let mut count_words = 0;
        for entry in glob(g_abstr).expect("Failed to read glob pattern") {
            match entry {
                Ok(path) => {
                    count_docs += 1;
                    let text = fs::read_to_string(&path).unwrap().to_lowercase();
                    let set = r_not_word
                        .split(text.as_str())
                        .filter(|x| !sws.contains(x))
                        .map(|x| x.to_string())
                        .collect::<HashSet<String>>();
                    count_words += set.len();
                    let doc_name = path.file_stem().unwrap().to_owned().into_string().unwrap();
                    map_doc_size.insert(doc_name.to_owned(), set.len() as u32);
                    map_doc_raw.insert(doc_name.to_owned(), text.to_lowercase());
                    for word in set {
                        *map_word_count.entry(word).or_insert(0) += 1;
                    }
                }
                Err(e) => println!("{:?}", e),
            }
        }

        DocAll {
            map_word_count,
            map_doc_raw,
            map_doc_size,
            count_words: count_words as u32,
            count_docs: count_docs as u32,
        }
    }
}
