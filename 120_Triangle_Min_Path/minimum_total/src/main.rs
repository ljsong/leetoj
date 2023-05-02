impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let mut min_cost = vec![0; triangle[triangle.len() - 1].len()];
        
        for ix in 0..triangle.len() {
            for jx in (0..triangle[ix].len()).rev() {
                if jx == 0{
                    min_cost[jx] = min_cost[jx] + triangle[ix][jx];
                } else if jx == triangle[ix].len() - 1 {
                    min_cost[jx] = min_cost[jx - 1] + triangle[ix][jx];
                } else {
                    min_cost[jx] = min_cost[jx].min(min_cost[jx - 1]) + triangle[ix][jx];
                }
            }
        }

        *min_cost.iter().min().unwrap()
    }
}

pub struct Solution;

fn main() {
    let mut triangle = Vec::new();
    triangle.push(vec![-11]);
    // triangle.push(vec![3, 4]);
    // triangle.push(vec![6, 5, 1]);
    // triangle.push(vec![4, 1, 8, 3]);

    println!("Minimum cost: {}", Solution::minimum_total(triangle));
}
