use glob::glob;
use regex::Regex;
use std::collections::HashSet;
use std::fs;

pub struct DocAll {
    data: Vec<HashSet<String>>,
}

impl DocAll {
    pub fn read_all(sws: &HashSet<&str>, g_abstr: &str) -> DocAll {
        let mut data = Vec::new();
        let r_not_word = Regex::new(r"[^\pL]").unwrap();
        for entry in glob(g_abstr).expect("Failed to read glob pattern") {
            match entry {
                Ok(path) => {
                    let text = fs::read_to_string(path)
                        .expect("The file could not be opened.")
                        .to_lowercase();
                    let set = r_not_word
                        .split(&text)
                        .map(|x| x.to_string())
                        .filter(|x| !sws.contains(x.as_str()))
                        .collect::<HashSet<String>>();
                    data.push(set);
                }
                Err(e) => println!("{:?}", e),
            }
        }
        return DocAll { data };
    }

    pub fn term_doc_frequency(&self, term: &str) -> u32 {
        return self
        .data
        .iter()
        .map(|doc| match doc.contains(term) {
            true => 1,
            false => 0,
        })
        .sum();
    }
    
    pub fn term_idf(&self, term: &str) -> f32 {
        let sum = self.term_doc_frequency(term);
        return (self.data.len() as f32).log(2.0)/(sum as f32);
    }
}
