#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word) {
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    std::cout << "Input a string: " << std::endl;
    string word;
    std::cin >> word;

    Solution s;
    std::cout << (s.exist(board, word) ? "EXIST" : "NOT EXIST") << std::endl;
    return 0;
}
