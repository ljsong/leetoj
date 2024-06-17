
/**
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 *
 * 示例 1:
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 示例 2:
 *
 * 输入: strs = [""]
 * 输出: [[""]]
 * 示例 3:
 *
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 */

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut results = Vec::new();
        if strs.is_empty() {
            return results;
        }

        use std::collections::HashMap;
        let  mut idx = 0;
        let mut classified = HashMap::new();

        while idx < strs.len() {
            let mut contents = strs[idx].chars().collect::<Vec<_>>();
            contents.sort_unstable();
            classified.entry(strs[idx].len()).or_insert(Vec::new()).push((idx, contents.iter().collect::<String>()));
            idx += 1;
        }

        for (_, v) in &mut classified {
            while !v.is_empty() {
                results.push(Vec::new());
                let (mut ix, len) = (0, results.len());
                let cur = &mut results[len - 1];
                let pivot = String::from(&v[0].1);

                while ix < v.len() {
                    if v[ix].1 == pivot {
                        cur.push(String::from(&strs[v[ix].0]));
                        v.remove(ix);
                    } else {
                        ix += 1;
                    }
                }
            }
        }

        results
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn test_anagrams() {
        let strs = Vec::from(["eat", "tea", "tan", "ate", "nat", "bat","eeaatt"])
            .into_iter().map(|s| s.to_string()).collect();
        // let strs = Vec::from(["hhhhu", "tttti", "hhuuh",
        //     "tttit", "hhhuh", "hhuhh", "tittt"]).into_iter().map(|s| s.to_string()).collect();
        // let strs = Vec::from([String::from("ac"), String::from("a")]);
        let results = Solution::group_anagrams(strs);
        assert_eq!(results, Vec::from([vec!["eat", "tea", "ate"], vec!["tan", "nat"], vec!["bat"], vec!["eeaatt"]]));
    }
}

fn main() {
    println!("Hello, world!");
}
