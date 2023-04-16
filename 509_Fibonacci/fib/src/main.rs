impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n < 2 {
            return n;
        }

        let mut ix = 2;
        let mut a = 0;
        let mut b = 1;
        let mut ans = 0;
        while ix <= n {
            ans = a + b;
            a = b;
            b = ans;
            ix += 1;
        }

        ans
    }
}

pub struct Solution;

fn main() {
    println!("the {}th fibonacci number is: {}", 30, Solution::fib(30));
}
