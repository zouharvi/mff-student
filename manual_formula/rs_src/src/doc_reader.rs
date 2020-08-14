use glob::glob;
use regex::Regex;
use std::collections::{HashMap, HashSet};
use std::fs;

pub struct DocAll {
    data: HashMap<String, u32>,
    no_documents: u32,
}

impl DocAll {
    pub fn read_all(sws: &HashSet<&str>, g_abstr: &str) -> DocAll {
        let mut map_data = HashMap::<String, u32>::new();
        let r_not_word = Regex::new(r"[^\pL]").unwrap();
        let mut no_documents = 0;
        for entry in glob(g_abstr).expect("Failed to read glob pattern") {
            match entry {
                Ok(path) => {
                    no_documents += 1;
                    let text = fs::read_to_string(path).unwrap().to_lowercase();
                    let set = r_not_word
                        .split(text.as_str())
                        .map(|x| x.to_string())
                        .filter(|x| !sws.contains(x.as_str()))
                        .collect::<HashSet<String>>();
                    for word in set {
                        *map_data.entry(word).or_insert(0) += 1;
                    }
                }
                Err(e) => println!("{:?}", e),
            }
        }

        DocAll {
            data: map_data,
            no_documents,
        }
    }

    pub fn term_idf(&self, term: &str) -> f32 {
        let sum = *self.data.get(term).unwrap_or(&0) as f32;
        (self.no_documents as f32).log(10.0) / (sum as f32)
    }
}
