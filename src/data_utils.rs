use lazy_static::lazy_static;
use regex::Regex;
use std::collections::{HashMap, HashSet};

pub fn compute_frq_deg<'a>(
    candidates: &Vec<Vec<String>>,
) -> (HashMap<&str, u32>, HashMap<&str, u32>) {
    let mut frq_map: HashMap<&str, u32> = HashMap::new();
    let mut deg_map: HashMap<&str, HashSet<&str>> = HashMap::new();

    for set in candidates {
        for w1 in set {
            *frq_map.entry(w1).or_insert(0) += 1;

            let deg_map_set = deg_map.entry(w1).or_insert(HashSet::new());
            for w2 in set {
                deg_map_set.insert(w2);
            }
        }
    }

    let deg = deg_map
        .iter()
        .map(|x| (*x.0, x.1.len() as u32))
        .collect::<HashMap<&str, u32>>();

    return (frq_map, deg);
}

fn word_heuristics(candidate: &Vec<String>) -> bool {
    lazy_static! {
        static ref R_VERB: Regex = Regex::new(r".*ed").unwrap();
    }
    return R_VERB.is_match(&candidate.last().unwrap()) || candidate.first().unwrap().len() <= 3;
}

pub fn create_candidates<'a>(words: Vec<&'a str>, sws: &HashSet<&str>) -> Vec<Vec<String>> {
    let mut buffer: Vec<String> = Vec::new();
    let mut candidates: Vec<Vec<String>> = Vec::new();

    lazy_static! {
        static ref R_UPPERCASE: Regex = Regex::new(r"\p{Lu}.+").unwrap();
    }

    for word in words {
        if sws.contains(&word.to_lowercase().as_str()) {
            if buffer.len() != 0 {
                if !word_heuristics(&buffer) {
                    candidates.push(buffer);
                }
                buffer = Vec::new();
            }
        } else if R_UPPERCASE.is_match(word) {
            if buffer.len() != 0 {
                if !word_heuristics(&buffer) {
                    candidates.push(buffer);
                }
                buffer = Vec::new();
            }
            buffer.push(word.to_lowercase());
        } else {
            buffer.push(word.to_lowercase());
        }
    }

    return candidates;
}
