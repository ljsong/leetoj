impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.len() == 1  {
            return if matrix[0].iter().filter(|x| { **x == '1' }).count() > 0 { 1 } else { 0 }
        }

        let (mut ping, mut pang)  = (Vec::new(), vec![0;matrix[0].len()]);
        for ix in 0..matrix[0].len() {
            ping.push(if matrix[0][ix] == '0' {0} else {1});
        }

        let mut max_side_len = *ping.iter().max().unwrap();
        for ix in 1..matrix.len() {
            for jx in 0..matrix[ix].len() {
                let cur_side_len;
                if ix & 0x1 == 1 {
                    cur_side_len = Self::calc_square(matrix[ix][jx], jx, &mut pang, &mut ping);
                } else {
                    cur_side_len = Self::calc_square(matrix[ix][jx], jx, &mut ping, &mut pang);
                }
                max_side_len = max_side_len.max(cur_side_len);
            }
        }

        max_side_len * max_side_len
    }

    fn calc_square(ch: char, col: usize, cur: &mut Vec<i32>, prev: &mut Vec<i32>) -> i32 {
        if col == 0 {
            cur[col] = if ch == '1' { 1 } else { 0 };
        } else {
            cur[col] = if ch == '1' { prev[col - 1].min(prev[col]).min(cur[col - 1]) + 1 } else { 0 };
        }

        cur[col]
    }
}

pub struct Solution;

#[cfg(test)]
mod tests{
    use super::*;

    #[test]
    fn test_max_square() {
        let matrix1 = vec![vec!['0', '1', '0', '1', '1'];1];
        assert_eq!(Solution::maximal_square(matrix1), 1);

        let matrix2 = vec![vec!['1','0','1','0','0'],vec!['1','0','1','1','1'],vec!['1','1','1','1','1'],vec!['1','0','0','1','0']];
        assert_eq!(Solution::maximal_square(matrix2), 4);

        let matrix3 = vec![vec!['1','1','1','0','0'],vec!['1','1','1','1','1'],vec!['1','1','1','1','1'],vec!['1','0','0','1','0']];
        assert_eq!(Solution::maximal_square(matrix3), 9);

        let matrix4 = vec![vec!['1', '0'], vec!['0', '0']];
        assert_eq!(Solution::maximal_square(matrix4), 1);
    }
}

fn main() {
    println!("Hello, world!");
}
