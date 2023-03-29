impl Solution {
    pub fn divide(dividend: i32, divisor: i32) -> i32 {
        if (divisor == 1) {
            return dividend;
        }
        
        if (divisor == -1) {
            if (dividend == i32::MIN) {
                return i32::MAX
            } else {
                return -dividend;
            }
        }
        
        let positive = (dividend ^ divisor) >= 0;
        let divisor_u = if divisor > 0 {divisor as u32}  else {(!divisor as u32) + 1};
        let mut attempt = divisor_u;
        let mut remaining = if dividend > 0 {dividend as u32} else {(!dividend as u32) + 1};
        let mut quotient = 0;
        
        while remaining >= divisor_u {
            let mut partial_quotient = 1;
            let half_check = remaining >> 1;
            while attempt <= half_check {
                attempt <<= 1;
                partial_quotient <<= 1;
            }
            remaining -= attempt;
            quotient += partial_quotient;
            attempt = divisor_u;
        }


        if positive {
            quotient
        } else {
            -quotient
        }
    }
}
