impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        if n < 2 {
            return n;
        } else if n == 2 {
            return 1;
        }

        let mut a = 0;
        let mut b = 1;
        let mut c = 1;
        let mut ix = 3;
        let mut ans = 0;

        while(ix <= n) {
            ans = a + b + c;
            a = b;
            b = c;
            c = ans;
            ix += 1;
        }

        ans
    }
}

pub struct Solution;

fn main() {
    println!("Hello, world!");
}
