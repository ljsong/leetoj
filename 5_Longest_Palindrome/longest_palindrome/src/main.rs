impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let mut palindrom_info: Vec<Vec<u32>> = Vec::new();
        let str_len = s.len();
        let seq = s.as_bytes();

        for ix in 0..str_len {
            palindrom_info.push(vec![0;str_len]);
            palindrom_info[ix][ix] = 1;
        }

        let mut start = 0;
        let mut end = 0;
        let mut max_len = 0;

        for ix in (0..str_len).rev() {
            for jx in ix..str_len {
                if seq[ix] == seq[jx] {
                    // len of seq[ix..jx] >= 3
                    if jx >= 1 && ix + 1 <= jx - 1 {
                        palindrom_info[ix][jx] = if palindrom_info[ix + 1][jx - 1] > 0 { palindrom_info[ix + 1][jx - 1] + 2 } else { 0 };
                    // len of seq[ix..jx] <= 2
                    } else if jx >= 1 && jx <= ix + 1 {
                        palindrom_info[ix][jx] = palindrom_info[ix][jx - 1] + 1
                    }
                    if palindrom_info[ix][jx] > max_len {
                        start = ix;
                        end = jx + 1;
                        max_len = palindrom_info[ix][jx];
                    }
                }
            }
        }

        String::from(&s[start..end])
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_palindrome() {
        let s = String::from("abab");
        assert_eq!(Solution::longest_palindrome(s).len(), 3);
    }
}

fn main() {
    println!("Hello, world!");
}

