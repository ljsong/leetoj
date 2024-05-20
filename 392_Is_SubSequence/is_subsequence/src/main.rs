impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let (mut ix, mut jx) = (0, 0);
        let (sstr, tstr) = (s.as_bytes(), t.as_bytes());
        while ix < s.len() && jx < t.len() {
            if sstr[ix] == tstr[jx] {
                ix += 1;
            }
            jx += 1;
        }

        return ix >= s.len()
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use crate::Solution;
    #[test]
    fn test_is_subsequence() {
        let s = String::from("axc");
        let t = String::from("ahbgdc");
        assert_eq!(Solution::is_subsequence(s, t), false);
    }
}

fn main() {
    println!("Hello, world!");
}