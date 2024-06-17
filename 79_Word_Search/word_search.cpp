#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if (board.empty() || word.empty()) {
            return false;
        }

        if (board.size() * board[0].size() < word.length()) {
            return false;
        }

        std::vector<std::pair<int, int>> origins;
        std::vector<bool> visited(board.size() * board[0].size(), false);
        for (int ix = 0; ix < board.size(); ++ix) {
            for (int jx = 0; jx < board[0].size(); ++jx) {
                if (board[ix][jx] == word[0]) {
                    origins.emplace_back(ix, jx);
                }
            }
        }

        for (auto [row, col] : origins) {
            visited[row * board[0].size() + col] = true;
            if (_exist(board, row, col, visited, word, 1)) {
                return true;
            }
            visited[row * board[0].size() + col] = false;
        }

        return false;
    }

private:
    bool _exist(const std::vector<std::vector<char>>& board, const int row, const int col,
                std::vector<bool>& visited, const std::string& word, const int pos) {
        if (pos == word.length()) {
            return true;
        }

        int bottom_bound = board.size() - 1, right_bound = board[0].size() - 1, width = board[0].size();
        bool result = false;
        visited[row * width + col] = true;
        if (row > 0 && board[row - 1][col] == word[pos] && !visited[(row - 1) * width + col]) {
            result |= _exist(board, row - 1, col, visited, word, pos + 1);
            visited[(row - 1) * width + col] = false;
        }

        if (row < bottom_bound && board[row + 1][col] == word[pos] && !visited[(row + 1) * width + col]) {
            result |= _exist(board, row + 1, col, visited, word, pos + 1);
            visited[(row + 1) * width + col] = false;
        }

        if (col > 0 && board[row][col - 1] == word[pos] && !visited[row * width + col - 1]) {
            result |= _exist(board, row, col - 1, visited, word, pos + 1);
            visited[row * width + col - 1] = false;
        }

        if (col < right_bound && board[row][col + 1] == word[pos] && !visited[row * width + col + 1]) {
            result |= _exist(board, row, col + 1, visited, word, pos + 1);
            visited[row * width + col + 1] = false;
        }

        return result;
    }
};

int main() {
    std::vector<std::vector<char>> matrix = {{'C', 'A', 'A'},{'A', 'A', 'A'},{'B', 'C', 'D'}};
    Solution s;
    std::cout << s.exist(matrix, "AAB") << std::endl;

}
