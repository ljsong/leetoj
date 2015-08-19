#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<pair<int, int> > board;
        vector<vector<string> > result;
        int row = 0;

        n_queens(row, n, board, result);

        return result;
    }

private:
    void n_queens(int row, int n, vector<pair<int, int> >& board, vector<vector<string> >& result) {
        if (row == n) {
            add_solution(board, result);
            return ;
        } 

        for(int column = 0; column < n; ++column) {
            if (can_place(row, column, board)) {
                board.push_back(make_pair(row, column));
                n_queens(row + 1, n, board, result);
                board.pop_back();
            }
        }
    }

    bool can_place(int row, int column, vector<pair<int, int> > board) {
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

    void add_solution(vector<pair<int, int> >& board, vector<vector<string> >& result) {
        string unplaced_row(board.size(), '.');
        vector<string> solution(board.size(), unplaced_row);

        for (int ix = 0; ix < board.size(); ++ix) {
            int row = board[ix].first;
            int column = board[ix].second;

            solution[row][column] = 'Q';
        }

        result.push_back(solution);
    }
};

int main() {
    Solution s;
    int n;
    std::cin >> n;

    vector<vector<string> > result = s.solveNQueens(n);
    for(int ix = 0; ix < result.size(); ++ix) {
        for(int jx = 0; jx < result[ix].size(); ++jx) {
            std::cout << result[ix][jx] << std::endl;
        }
        std::cout << "-----------------------" << std::endl;
    }

    return 0;
}
