impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let mut positive_pos = 0;
        let mut ans: Vec<i32> = Vec::new();

        while positive_pos < nums.len() && nums[positive_pos] < 0 {
            positive_pos += 1;
        }
        
        let left = &nums[..positive_pos];
        let mut ix = positive_pos;
        
        for num in left.iter().rev() {
            if ix >= nums.len() {
                ans.push(num * num);
                continue;
            }
            
            while ix < nums.len() && num.abs() > nums[ix] {
                ans.push(nums[ix] * nums[ix]);
                ix += 1;
            }
            ans.push(num * num);
        }
        
        while ix < nums.len(){
            ans.push(nums[ix] * nums[ix]);
            ix += 1;
        }
        
        ans
    }
}
