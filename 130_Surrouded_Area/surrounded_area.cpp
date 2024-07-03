#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        std::unordered_map<int, int> hash;
        std::unordered_map<int, int> count;

        auto width = board[0].size(), height = board.size();
        for (int ix = 0; ix < height; ++ix) {
            for (int jx = 0; jx < width; ++jx) {
                auto index = ix * width + jx;
                hash[index] = index;
                count[index] = 1;
            }
        }

        // from left to right, top to bottom
        for (int ix = 0; ix < height; ++ix) {
            for (int jx = 0; jx < width; ++jx) {
                if (ix < height - 1 && board[ix][jx] == board[ix + 1][jx]) {
                    Union(hash, count, ix * width + jx, (ix + 1) * width + jx);
                }
                if (jx < width - 1 && board[ix][jx] == board[ix][jx + 1]) {
                    Union(hash, count, ix * width + jx, ix * width + jx + 1);
                }
            }
        }

        std::unordered_set<int> ignores;
        for (int ix = 0; ix < height; ++ix) {
            for (int jx = 0; jx < width; ++jx) {
                if (board[ix][jx] != 'X') {
                    auto num = Find(hash, ix * width + jx);
                    if (ix == 0 || ix == height -1 || jx == 0 || jx == width - 1) {
                        std::cout << "Insert " << num << std::endl;
                        ignores.insert(num);
                    }
                }
            }
        }

        for (int ix = 0; ix < height; ++ix) {
            for (int jx = 0; jx < width; ++jx) {
                std::cout << hash[ix * width + jx] << " ";
            }
            std::cout << std::endl;
        }

        for (int ix = 0; ix < height; ++ix) {
            for (int jx = 0; jx < width; ++jx) {
                if (board[ix][jx] != 'X' && ignores.count(Find(hash, ix * width + jx)) == 0) {
                    board[ix][jx] = 'X';
                }
            }
        }
    }

private:
    void Union(std::unordered_map<int, int>& hash, std::unordered_map<int, int>& count, int a, int b) {
        a = Find(hash, a);
        b = Find(hash, b);

        if (a == b) {
            return;
        }

        if (count[b] > count[a]) {
            hash[a] = b;
            count[b] += count[a];
        } else {
            hash[b] = a;
            count[a] += count[b];
        }
    }

    int Find(std::unordered_map<int, int>& hash, int a) {
        return a == hash[a] ? a : hash[a] = Find(hash, hash[a]);
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> board = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    s.solve(board);

    for (int ix = 0; ix < board.size(); ++ix) {
        for (int jx = 0; jx < board[0].size(); ++jx) {
            std::cout << board[ix][jx] << " ";
        }

        std::cout << std::endl;
    }
}