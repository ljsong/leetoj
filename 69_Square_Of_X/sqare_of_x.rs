impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut low : i32 = 0;
        let mut high : i32 = 46341;   // sqrt(i32::MAX) + 1
        let mut guess = 0;
        
        while (high - low).abs() > 1  {
            guess = (low + high) >> 1;
            if guess * guess < x {
                low = guess;
            } else if (guess * guess == x) {
                return guess;
            } else {
                high = guess
            }
        }
        
        low
    }
}
