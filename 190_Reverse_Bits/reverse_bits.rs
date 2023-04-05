impl Solution {
    pub fn reverse_bits(x: u32) -> u32 {
        let mut num: u32 = x;
        let mut ans: u32 = 0;
        let mut bits: i8 = 31;
    
        while num != 0 {
            if num & 0x1 != 0 {
                ans += (1 << bits);
            }
            num = num >> 1;
            bits -= 1;
        }
    
        ans
    }
}
