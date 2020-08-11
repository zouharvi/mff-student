use regex::Regex;
use std::collections::HashMap;
use std::collections::HashSet;
use std::fs;
use std::iter::FromIterator;

const F_STOPWORDS: &str = "./data/en/stopwords.txt";
const F_DOCUMENT: &str = "./data/en/kufre.txt";

fn create_candidates<'a>(words: &Vec<String>, sws: HashSet<String>) -> Vec<Vec<String>> {
    let mut buffer: Vec<String> = Vec::new();
    let mut candidates: Vec<Vec<String>> = Vec::new();

    let uppercase_regex = Regex::new(r"[A-Z].+").unwrap();
    let word_regex = Regex::new(r"[a-zA-Z]+").unwrap();

    for word in words {
        if !word_regex.is_match(word) {
            continue;
        }

        if sws.contains(word) || uppercase_regex.is_match(word) {
            if buffer.len() != 0 {
                candidates.push(buffer);
                buffer = Vec::new();
            }
        } else {
            buffer.push(word.to_string())
        }
    }
    return candidates;
}

fn crf_key<'a>(w1: &String, w2: &String) -> String {
    let key: String;
    if w1 < w2 {
        key = format!("{}-{}", w1, w2);
    } else {
        key = format!("{}-{}", w2, w1);
    }
    return key;
}

fn compute_crf_frq_deg<'a, 'b>(
    candidates: &Vec<Vec<String>>,
) -> (
    HashMap<String, u32>,
    HashMap<String, u32>,
    HashMap<String, u32>,
) {
    let mut cfs: HashMap<String, u32> = HashMap::new();
    let mut frq: HashMap<String, u32> = HashMap::new();
    let mut deg: HashMap<String, u32> = HashMap::new();
    let mut deg_array: HashMap<String, HashSet<String>> = HashMap::new();

    for set in candidates {
        for w1 in set {
            if !deg_array.contains_key(w1) {
                deg_array.insert(w1.to_string(), HashSet::new());
            }

            let val: u32 = *frq.get(w1).unwrap_or(&0);
            frq.insert(w1.to_string(), val + 1);

            for w2 in set {
                if w2 > w1 {
                    let key: String = crf_key(&w1, &w2);
                    let val: u32 = *cfs.get(&key).unwrap_or(&0);
                    cfs.insert(key, val + 1);
                }
                
                deg_array.get_mut(w1).unwrap().insert(w2.to_string());
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
    let sws: HashSet<String> = HashSet::from_iter(sws_raw.lines().map(|x| x.to_string()));

    println!("Opening document from '{}'", F_DOCUMENT);
    let doc_raw = fs::read_to_string(F_DOCUMENT).expect("The file could not be opened.");

    println!("");

    let doc_words: Vec<String> = Regex::new(r"\W+")
        .unwrap()
        .split(&doc_raw.to_owned())
        .map(|x| x.to_string())
        .collect();

    let candidates = create_candidates(&doc_words, sws);

    let (_cfrs, frqs, degs) = compute_crf_frq_deg(&candidates);
    
    let mut rat : HashMap<String, f32> = HashMap::new();
    for (key, f_val) in frqs {
        let d_val = degs.get(&key).unwrap().clone() as f32;
        rat.insert(key, d_val/(f_val as f32));
    }
    
    let mut keywords : HashMap<String, f32> = HashMap::new();
    for candidate in candidates {
        let mut sum: f32 = 0.0;
        let length: u32 = candidate.len() as u32;
        let key : String = candidate.join(" ");
        for word in &candidate {
            sum += rat.get(word).unwrap();
        }
        let mut score = sum/f32::powf(length as f32, 1.8);
        if keywords.contains_key(&key) {
            score += 1.0;
        }
        keywords.insert(key, score);
    }

    let mut keyword_vec:Vec<(&String, &f32)> = keywords.iter().collect();
    keyword_vec.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap());

    for n in 1..20 {
        let (key, val) = keyword_vec.get(n).unwrap();
        println!("{}: {}", key, val);
    }
}
