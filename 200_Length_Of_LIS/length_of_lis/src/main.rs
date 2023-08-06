impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        if nums.len() == 0 || nums.len() == 1 {
            return nums.len() as i32;
        }

        let mut length = vec![0;nums.len()];
        length[0] = 1;
        for ix in 1..nums.len() {
            for jx in 0..ix {
                if nums[ix] > nums[jx] {
                    length[ix] = length[ix].max(length[jx]);
                }
            }
            length[ix] += 1;
        }

        *length.iter().max().unwrap()
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn test_length_of_lis() {
        let nums = vec![10, 9, 2, 5, 3, 7, 101, 18];
        assert_eq!(Solution::length_of_lis(nums), 4);

        let nums1 = vec![3, 1, 6, 2, 2, 7];
        assert_eq!(Solution::length_of_lis(nums1), 3);

        let nums2 = vec![0, 1, 0, 3, 2, 3];
        assert_eq!(Solution::length_of_lis(nums2), 4);
    }
}
fn main() {
    println!("Hello, world!");
}
