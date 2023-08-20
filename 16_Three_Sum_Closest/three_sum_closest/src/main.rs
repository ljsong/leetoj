impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        if nums.len() == 3 {
            return nums.iter().sum();
        }

        let mut nums = nums.clone();
        nums.sort();
        let mut closest_target = i32::MAX;

        for ix in 0..nums.len() {
            let (mut low, mut high) = (ix + 1, nums.len() - 1);
            while low < high {
                if nums[low] + nums[high] + nums[ix] < target {
                    low = low + 1;
                } else if nums[low] + nums[high] + nums[ix] > target {
                    high = high - 1;
                } else {
                    return target;
                }
            }
        }

        closest_target
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_three_sum_closest() {
        let nums = vec![-1, 2, 1, -4];
        assert_eq!(Solution::three_sum_closest(nums, 1), 2);
    }
}

fn main() {
    println!("Hello, world!");
}
