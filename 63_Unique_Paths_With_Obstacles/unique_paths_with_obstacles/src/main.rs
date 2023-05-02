impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let mut paths = Vec::new();
        for ix in 0..obstacle_grid.len() {
            paths.push(vec![0; obstacle_grid[ix].len()]);
        }

        paths[0][0] = if obstacle_grid[0][0] == 1 {0} else {1};
        for ix in 0..obstacle_grid.len() {
            for jx in 0..obstacle_grid[ix].len() {
                if obstacle_grid[ix][jx] == 1 {
                    continue;
                }

                let top_paths = if ix >= 1 {paths[ix - 1][jx]} else {0};
                let left_paths = if jx >= 1 {paths[ix][jx - 1]} else {0};
                paths[ix][jx] += top_paths + left_paths;
            }
        }

        paths[paths.len() - 1][paths[0].len() - 1]
    }
}

pub struct Solution;

fn main() {
    let first = vec![0, 0, 0];
    let second = vec![0, 0, 0];
    let third = vec![0, 0, 0];
    let obstacle_grid = vec![first, second, third];
    println!("Total paths: {}", Solution::unique_paths_with_obstacles(obstacle_grid));
}
