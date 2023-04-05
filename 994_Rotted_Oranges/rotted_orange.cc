#include <vector>
#include <deque>
#include <utility>
#include <iostream>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) {
            return -1;
        }
        
        int rows = grid.size(), cols = grid[0].size();
        std::vector<bool> visited(rows * cols, false);
        std::deque<std::pair<int, int>> rotted_queue;

        for (int ix = 0; ix < rows; ++ix) {
            for (int jx = 0; jx < cols; ++jx) {
                if (grid[ix][jx] == 2) {
                    rotted_queue.push_back(std::make_pair(ix, jx));
                    visited[ix * cols + jx] = true;
                } else if (grid[ix][jx] == 0) {
                    visited[ix * cols + jx] = true;
                }
            }
        }
        //insert a mark to increase the minutes
        rotted_queue.push_back(std::make_pair(-1, -1));

        int minutes = 0;
        while(!rotted_queue.empty()) {
            auto& pos = rotted_queue.front();
            int row = pos.first, col = pos.second;
            if (row == -1 && col == -1) {
                rotted_queue.pop_front();
                if (rotted_queue.empty()) {
                    break;
                }
                minutes++;
                rotted_queue.push_back(std::make_pair(-1, -1));
                continue;
            }

            visited[row * cols + col] = true;
            int left = col - 1;
            if (left >= 0 && grid[row][left] == 1) {
                grid[row][left] = 2;
                rotted_queue.push_back(std::make_pair(row, left));
            }

            int right = col + 1;
            if (right < cols && grid[row][right] == 1) {
                grid[row][right] = 2;
                rotted_queue.push_back(std::make_pair(row, right));
            }

            int up = row - 1;
            if (up >= 0 && grid[up][col] == 1) {
                grid[up][col] = 2;
                rotted_queue.push_back(std::make_pair(up, col));
            }

            int down = row + 1;
            if (down < rows && grid[down][col] == 1) {
                grid[down][col] = 2;
                rotted_queue.push_back(std::make_pair(down, col));
            }

            rotted_queue.pop_front();
        }

        for (int ix = 0; ix < rows * cols; ++ix) {
            if (!visited[ix]) {
                return -1;
            }
        }

        return minutes;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    std::cout << s.orangesRotting(grid) << std::endl;

    return 0;
}
