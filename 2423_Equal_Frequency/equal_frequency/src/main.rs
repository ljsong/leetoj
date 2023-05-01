impl Solution {
    pub fn equal_frequency(word: String) -> bool {
        use std::collections::HashMap;
        let mut counts = HashMap::new();
        for ch in word.chars() {
            let count = counts.entry(ch).or_insert(0);
            *count += 1;
        }

        if counts.len() == word.len() || counts.len() == 1 {
            return true;
        }
        
        let max_val = counts.iter().max_by(|a, b| a.1.cmp(&b.1)).map(|(_k, v)| v);
        let max_val = max_val.unwrap();
        let mut max_counts = 0;
        let mut other_counts = 0;
        let mut other_val = -1;
        for (_k, v) in &counts {
            if v == max_val {
                max_counts += 1;
            } else {
                other_counts += 1;
                if other_val != -1 && *v != other_val {
                    return false;
                }
                other_val = *v;
            }
        }

        if max_counts == 1 && max_val - 1 == other_val {
            return true;
        } else if other_counts == 1 && other_val == 1 {
            return true;
        }

        false
    }
}

pub struct Solution;

fn main() {
    let word = String::from("aaabbbcc");
    println!("{}", Solution::equal_frequency(word));
}
