impl Solution {
    pub fn longest_palindrome_subseq(s: String) -> i32 {
        if s.len() == 0 || s.len() == 1 {
            return s.len() as i32;
        }

        let (mut cur, mut prev) = (vec![0;s.len()], vec![0;s.len()]);
        let seq = s.as_bytes();
        for ix in (0..s.len()).rev() {
            // cur[jx] means the max length of palindrome subseq from ix to jx
            cur[ix] = 1;
            prev.copy_from_slice(&cur);
            for jx in ix..s.len() {
                if jx == ix + 1 {
                    cur[jx] = if seq[ix] == seq[jx] { cur[jx - 1] + 1 } else { cur[jx - 1] };
                } else if jx >= ix + 2{
                    cur[jx] = if seq[ix] == seq[jx] { prev[jx - 1] + 2 } else { cur[jx - 1].max(prev[jx]) };
                }
            }
        }

        cur[s.len() - 1]
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_palindrome_subseq() {
        let s = String::from("a");
        assert_eq!(Solution::longest_palindrome_subseq(s), 1);

        let s1 = String::from("bbbab");
        assert_eq!(Solution::longest_palindrome_subseq(s1), 4);

        let s2 = String::from("cbbd");
        assert_eq!(Solution::longest_palindrome_subseq(s2), 2);
    }
}

fn main() {
    println!("Hello, world!");
}
