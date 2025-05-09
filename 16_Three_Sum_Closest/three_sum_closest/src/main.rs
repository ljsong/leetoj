impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        if nums.len() == 3 {
            return nums.iter().sum();
        }

        let mut nums = nums.clone();
        nums.sort();
        let mut closest_target = i32::MAX;

        for ix in 0..nums.len() - 2 {
            let (mut low, mut high) = (ix + 1, nums.len() - 1);
            while low < high {
                let sum = nums[low] + nums[high] + nums[ix];

                if (sum - target).abs() < (closest_target - target).abs() {
                    closest_target = sum;
                }
                if sum < target {
                    low = low + 1;
                } else if sum > target {
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
        let nums = vec![2, 3, 8, 9, 10];
        assert_eq!(Solution::three_sum_closest(nums, 16), 15);
    }
}

fn main() {
    println!("Hello, world!");
}
