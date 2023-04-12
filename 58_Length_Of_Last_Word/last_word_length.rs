impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
    let mut count = 0;
    
    for c in s.chars().rev() {
        if c == ' ' {
            if count == 0 {
                continue;
            } else {
                break;
            }
        }
        count += 1;
    }
    
    count
    }
}
