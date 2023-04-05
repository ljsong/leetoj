#include <vector>
#include <iostream>
#include <deque>
#include <utility>
#include <limits>

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        if (mat.empty()) {
            return mat;
        }

        int rows = mat.size(), cols = mat[0].size();
        int start_row = -1, start_col = -1;
        std::deque<std::pair<int, int>> pos_queue; 
        std::vector<bool> visited(rows * cols, false);

        for (int ix = 0; ix < rows; ++ix) {
            for (int jx = 0; jx < cols; ++jx) {
                if (mat[ix][jx] == 0) {
                    start_row = ix;
                    start_col = jx;
                } else {
                    mat[ix][jx] = MAX_DIST;
                }
            }
        }
        pos_queue.push_back(std::make_pair(start_row, start_col));
        visited[start_row * cols + start_col] = true;

        while(!pos_queue.empty()) {
            auto& pos = pos_queue.front();
            update_neighbor(mat, pos_queue, visited, pos.first, pos.second);
            pos_queue.pop_front(); 
        }
        
        return mat;
    }

private:
    void update_neighbor(std::vector<std::vector<int>>& mat,
            std::deque<std::pair<int, int>>& pos_queue,
            std::vector<bool>& visited, int row, int col) {
        int cur_dist = mat[row][col] + 1;
        int rows = mat.size(), cols = mat[0].size();

        int left = col - 1;
        if (left >= 0) {
            calc_dist(mat, pos_queue, visited, row, left, cur_dist);
        }

        int right = col + 1;
        if (right < cols) {
            calc_dist(mat, pos_queue, visited, row, right, cur_dist);
        }
        
        int up = row - 1;
        if (up >= 0) {
            calc_dist(mat, pos_queue, visited, up, col, cur_dist);
        }

        int down = row + 1;
        if (down < rows) {
            calc_dist(mat, pos_queue, visited, down, col, cur_dist);
        }
    }

    void calc_dist(std::vector<std::vector<int>>& mat,
            std::deque<std::pair<int, int>>& pos_queue,
            std::vector<bool>& visited, int row, int col, int cur_dist) {
        int rows = mat.size(), cols = mat[0].size();

        if (cur_dist < mat[row][col]) {
            mat[row][col] = cur_dist;
            // we need to re-evaluate the neighbor around this cell
            visited[row * cols + col] = false;
        }

        if (!visited[row * cols + col]) {
            pos_queue.push_back(std::make_pair(row, col));
            visited[row * cols + col] = true;
        }
    }

private:
    const int MAX_DIST{std::numeric_limits<int>::max()};
};

int main() {
    Solution s;
    std::vector<std::vector<int>> mat = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    s.updateMatrix(mat);

    for (int ix = 0; ix < mat.size(); ++ix) {
        for (int jx = 0; jx < mat[ix].size(); ++jx) {
            std::cout << mat[ix][jx] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
