impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        if nums.len() == 0 {
            return 0;
        } else if nums.len() == 1 {
            return nums[0];
        }
        
        let mut total = vec![0; nums.len()];
        total[0] = nums[0];
        total[1] = if nums[1] > nums[0] {nums[1]} else {nums[0]};
        
        for ix in 2..nums.len() {
            if total[ix - 1] > total[ix - 2] + nums[ix] {
                total[ix] = total[ix - 1];
            } else {
                total[ix] = total[ix - 2] + nums[ix];
            }
        }
        
        total[nums.len() - 1]
    }
}
pub struct Solution;

pub fn main() {
    let nums = vec![2, 1, 1, 2];
    println!("Total got: {}", Solution::rob(nums));
}
