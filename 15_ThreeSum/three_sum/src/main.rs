impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        if nums.len() == 3 {
            return if nums.iter().fold(0, |x, y| x + y) == 0 { vec![nums] } else { vec![] };
        }
        let mut nums = nums.clone();
        let mut ans = Vec::new();
        nums.sort();

        for ix in 0..nums.len() {
            if nums[ix] > 0 {
                println!("ans = {:?}", ans);
                return ans;
            }

            if ix > 0 && nums[ix] == nums[ix - 1] {
                continue;
            }

            let (mut low, mut high) = (ix + 1, nums.len() - 1);
            while low < high {
                if nums[ix] + nums[low] + nums[high] < 0 {
                    low += 1;
                } else if nums[ix] + nums[low] + nums[high] > 0 {
                    high -= 1;
                } else {
                    ans.push(vec![nums[ix], nums[low], nums[high]]);
                    while low < high && nums[low] == nums[low + 1] {
                        low += 1;
                    }
                    while low < high && nums[high] == nums[high - 1] {
                        high -= 1;
                    }
                    low += 1;
                    high -= 1;
                }
            }
        }

        println!("ans = {:?}", ans);
        ans
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_three_summ() {
        let nums = vec![-1, 0, 1, 2, -1, 4];
        Solution::three_sum(nums);
    }
}
fn main() {
    println!("Hello, world!");
}
