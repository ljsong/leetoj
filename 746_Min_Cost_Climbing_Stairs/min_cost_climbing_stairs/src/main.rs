impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut tn_2 = cost[0];
        let mut tn_1 = cost[1];

        for ix in 2..cost.len() {
            let tn = (tn_1 + cost[ix]).min(tn_2 + cost[ix]);
            tn_2 = tn_1;
            tn_1 = tn;
        } 

        return tn_1.min(tn_2);
    }
}

pub struct Solution;

fn main() {
    let cost = vec![1, 100, 1, 1, 1, 100, 1, 1, 100, 1];
    println!("Total cost: {}", Solution::min_cost_climbing_stairs(cost));
}
