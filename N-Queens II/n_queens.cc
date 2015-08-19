#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

class Solution{
public:
    int totalNQueens(int n) {
        vector<pair<int, int> > board;
        int total_count = 0, row = 0;

        n_queens(row, n, board, total_count);

        return total_count;
    }

private:
    void n_queens(int row, int n, vector<pair<int, int> >& board, int& total_count) {
        if (row == n) {
            total_count += 1;
            return ;
        } 

        for(int column = 0; column < n; ++column) {
            if (can_place(row, column, board)) {
                board.push_back(make_pair(row, column));
                n_queens(row + 1, n, board, total_count);
                board.pop_back();
            }
        }
    }

    bool can_place(int row, int column, const vector<pair<int, int> >& board) {
        for(int ix = 0; ix < board.size(); ++ix) {
            int placed_row = board[ix].first;
            int placed_column = board[ix].second;

            if (column == placed_column) {
                return false;
            } else if (abs(row - placed_row) == abs(column - placed_column)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    int n;
    std::cin >> n;
    std::cout << s.totalNQueens(n) << std::endl;

    return 0;
}
