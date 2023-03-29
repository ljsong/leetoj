impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
        let mut low = 1;
        let mut high = n;
        
        while low <= high {
            let mid = ((high - low) >> 1) + low; 
            
            if self.isBadVersion(mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        low
    }
}
