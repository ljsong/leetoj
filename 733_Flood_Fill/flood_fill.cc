#include <vector>
#include <deque>
#include <utility>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> floodFill(
            std::vector<std::vector<int>>& image, int sr, int sc, int color) {
        if (image.empty() || color == image[sr][sc]) {
            return image;
        }

        std::deque<std::pair<int, int>> idx_queue;
        int rows = image.size(), cols = image[0].size();
        int orig_color = image[sr][sc];
        image[sr][sc] = color;
        idx_queue.push_back(std::make_pair(sr, sc));

        while(!idx_queue.empty()) {
            auto& pos = idx_queue.front();

            int left = pos.second - 1;
            if (left >= 0 && image[pos.first][left] == orig_color) {
                image[pos.first][left] = color;
                idx_queue.push_back(std::make_pair(pos.first, left));
            }
            
            int right = pos.second + 1;
            if (right < cols && image[pos.first][right] == orig_color) {
                image[pos.first][right] = color;
                idx_queue.push_back(std::make_pair(pos.first, right));
            }

            int up = pos.first - 1;
            if (up >= 0 && image[up][pos.second] == orig_color) {
                image[up][pos.second] = color;
                idx_queue.push_back(std::make_pair(up, pos.second));
            }

            int down = pos.first + 1;
            if (down < rows && image[down][pos.second] == orig_color) {
                image[down][pos.second] = color;
                idx_queue.push_back(std::make_pair(down, pos.second));
            }

            idx_queue.pop_front();
        }

        return image;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    s.floodFill(image, 1, 1, 2);
    for (int ix = 0; ix < image.size(); ++ix) {
        for (int jx = 0; jx < image[ix].size(); ++jx) {
            std::cout << image[ix][jx] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
