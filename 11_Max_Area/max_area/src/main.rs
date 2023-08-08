impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut left, mut right) = (0, height.len() - 1);
        let mut max_val = 0;

        while left < right {
            let cur_area = height[left].min(height[right]) * (right - left) as i32;
            max_val = max_val.max(cur_area);
            if height[left] < height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }

        max_val
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn test_max_area() {
        let height = vec![1, 8, 6, 2, 5, 4, 8, 3, 7];
        assert_eq!(Solution::max_area(height), 49);
    }
}
fn main() {
    println!("Hello, world!");
}
