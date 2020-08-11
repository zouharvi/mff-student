use regex::Regex;
use std::collections::HashMap;
use std::collections::HashSet;
use std::fs;
use std::iter::FromIterator;

const F_STOPWORDS: &str = "./data/en/stopwords.txt";
const F_DOCUMENT: &str = "./data/en/kufre.txt";
const LENGTH_POWER: f32 = 1.2;
const DUPLICITY_SCORE: f32 = 0.1;

fn create_candidates<'a>(words: &[&str], sws: HashSet<&str>) -> Vec<Vec<String>> {
    let mut buffer: Vec<String> = Vec::new();
    let mut candidates: Vec<Vec<String>> = Vec::new();

    let r_uppercase = Regex::new(r"\p{Lu}.+").unwrap();
    let r_word = Regex::new(r"\pL+").unwrap();

    for word in words {
        if !r_word.is_match(word) {
            continue;
        }

        if sws.contains(&word.to_lowercase().as_str()) {
            if buffer.len() != 0 {
                candidates.push(buffer);
                buffer = Vec::new();
            }
        } else if r_uppercase.is_match(word) {
            if buffer.len() != 0 {
                candidates.push(buffer);
                buffer = Vec::new();
            }
            buffer.push(word.to_lowercase());
        } else {
            buffer.push(word.to_lowercase());
        }
    }

    return candidates;
}

fn crf_key<'a>(w1: &str, w2: &str) -> String {
    let key: String;
    if w1 < w2 {
        key = format!("{}-{}", w1, w2);
    } else {
        key = format!("{}-{}", w2, w1);
    }
    return key;
}

fn compute_crf_frq_deg<'a>(
    candidates: &[Vec<String>],
) -> (HashMap<String, u32>, HashMap<String, u32>, HashMap<String, u32>) {
    let mut cfs: HashMap<String, u32> = HashMap::new();
    let mut frq: HashMap<String, u32> = HashMap::new();
    let mut deg: HashMap<String, u32> = HashMap::new();
    let mut deg_array: HashMap<String, HashSet<&str>> = HashMap::new();

    for set in candidates {
        for w1 in set {
            if !deg_array.contains_key(w1.as_str()) {
                deg_array.insert(w1.clone(), HashSet::new());
            }

            let val: u32 = *frq.get(w1.as_str()).unwrap_or(&0);
            frq.insert(w1.clone(), val + 1);

            for w2 in set {
                if w2 > w1 {
                    let key: String = crf_key(w1, w2);
                    let val: u32 = *cfs.get(&key).unwrap_or(&0);
                    cfs.insert(key, val + 1);
                }
                deg_array.get_mut(w1.as_str()).unwrap().insert(w2);
            }
        }
    }

    for (key, arr) in deg_array {
        deg.insert(key, arr.len() as u32);
    }

    return (cfs, frq, deg);
}

fn main() {
    println!("Opening stopwords from '{}'", F_STOPWORDS);
    let sws_raw: String = fs::read_to_string(F_STOPWORDS).expect("The file could not be opened.");
    let sws: HashSet<&str> = HashSet::from_iter(sws_raw.lines());

    println!("Opening document from '{}'", F_DOCUMENT);
    let doc_raw: String = fs::read_to_string(F_DOCUMENT).expect("The file could not be opened.");

    println!("");

    let doc_words: Vec<&str> = Regex::new(r"\W+").unwrap().split(&doc_raw).collect();
    let candidates = create_candidates(&doc_words, sws);

    let (_cfrs, frqs, degs) = compute_crf_frq_deg(&candidates);

    let mut rat: HashMap<String, f32> = HashMap::new();
    for (key, f_val) in frqs {
        let d_val = degs.get(&key).unwrap().clone() as f32;
        rat.insert(key, d_val / (f_val as f32));
    }

    let mut keywords: HashMap<String, f32> = HashMap::new();
    for candidate in candidates {
        let mut sum: f32 = 0.0;
        let length: u32 = candidate.len() as u32;
        let key: String = candidate.join(" ");
        for word in &candidate {
            sum += rat.get(word.as_str()).unwrap();
        }
        let mut score = sum / f32::powf(length as f32, LENGTH_POWER);
        if keywords.contains_key(key.as_str()) {
            score += DUPLICITY_SCORE;
        }
        keywords.insert(key, score);
    }

    let mut keyword_vec: Vec<(&str, &f32)> = keywords.iter().map(|(k,v)| (k.as_str(), v)).collect();
    keyword_vec.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap());

    println!("Score  Keyword");
    for n in 1..20 {
        let (key, val) = keyword_vec.get(n).unwrap();
        println!("{:.3}: {}", val, key);
    }
}
