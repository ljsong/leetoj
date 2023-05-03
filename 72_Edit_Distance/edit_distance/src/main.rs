impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        if word1.len() == 0 {
            return word2.len() as i32;
        }
        
        if word2.len() == 0 {
            return word1.len() as i32;
        }

        let mut table = Vec::new();
        // allocate extra one column and row
        // table[0][ix] means pattern string is empty
        // table[ix][0] means text string is empty
        for ix in 0..word1.len() + 1 {
            table.push(vec![0; word2.len() + 1])
        }

        // means when pattern string is empty, how many operations we need to do to change to text string
        for ix in 0..word2.len() + 1 {
            table[0][ix] = ix as i32;
        }

        for ix in 0..word1.len() + 1 {
            table[ix][0] = ix as i32;
        }

        // table[ix][jx] means minimum operations to do for P0...P(i - 1) and T0...T(j - 1)
        for ix in 0..word1.len() {
            for jx in 0..word2.len() {
                let sub_val = if word2.as_bytes()[jx] == word1.as_bytes()[ix] {0} else {1};
                let match_subs_cost = table[ix][jx] + sub_val;
                let del_cost = table[ix + 1][jx] + 1;
                let insert_cost = table[ix][jx + 1] + 1;

                table[ix + 1][jx + 1] = match_subs_cost.min(insert_cost).min(del_cost);
            }
        }

        table[word1.len()][word2.len()]
    }
}

pub struct Solution;

fn main() {
    let word1 = String::from("sea");
    let word2 = String::from("eat");

    println!("Edit distance is: {}", Solution::min_distance(word1, word2));
}
