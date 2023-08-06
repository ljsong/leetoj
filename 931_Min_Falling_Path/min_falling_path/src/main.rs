impl Solution {
    pub fn min_falling_path_sum(matrix: Vec<Vec<i32>>) -> i32 {
        if matrix.len() == 0 {
            return 0
        }

        if matrix.len() == 1 {
            return matrix[0][0];
        }

        // here we can not use a vec `row` to store the min path sum
        // because after we updating row[ix] it will affect the check of row[ix + 1]
        // we use a ping-pang buffer here and according to the row number is even or odd to switch
        let mut ping = Vec::new();
        let mut pang = vec![0;matrix[0].len()];
        for ix in 0..matrix[0].len() {
            ping.push(matrix[0][ix]);
        }

        for ix in 1..matrix.len() {
            for jx in 0..matrix[ix].len() {
                if ix % 2 == 0 {
                    let left_top = if jx >= 1 {pang[jx - 1]} else {i32::MAX};
                    let right_top = if jx + 1 < matrix[ix].len() {pang[jx + 1]} else {i32::MAX};
                    ping[jx] = left_top.min(pang[jx]).min(right_top) + matrix[ix][jx];
                } else {
                    let left_top = if jx >= 1 {ping[jx - 1]} else {i32::MAX};
                    let right_top = if jx + 1 < matrix[ix].len() {ping[jx + 1]} else {i32::MAX};
                    pang[jx] = left_top.min(ping[jx]).min(right_top) + matrix[ix][jx];
                }
            }
        }

        if matrix.len() % 2 != 0 {
            return *ping.iter().min().unwrap();
        }

        *pang.iter().min().unwrap()
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn test_falling_path() {
        let matrix1 = vec![vec![2, 1, 3], vec![6, 5, 4], vec![7, 8, 9]];
        assert_eq!(Solution::min_falling_path_sum(matrix1), 13);

        let matrix2 = vec![vec![-19, 57], vec![-40, -5]];
        assert_eq!(Solution::min_falling_path_sum(matrix2), -59);
    }
}

fn main() {
    println!("Hello, world!");
}
