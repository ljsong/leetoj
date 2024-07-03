#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;

        if (s.empty()) {
            return result;
        }

        std::vector<std::vector<int>> matrix;
        //matrix[ix][jx] means the length of a palindrome substring
        for (int ix = 0; ix < s.length(); ++ix) {
            matrix.push_back(std::vector<int>(s.length(), 0));
            matrix[ix][ix] = 1;
        }

        for (int ix = s.length() - 1; ix >= 0; --ix) {
            for (int jx = ix + 1; jx < s.length(); ++jx) {
                if (s[ix] != s[jx]) {
                    continue;
                }

                if (jx <= ix + 1) {
                    matrix[ix][jx] = matrix[ix][jx - 1] + 1;
                }  else {
                    matrix[ix][jx] = matrix[ix + 1][jx - 1] > 0 ? matrix[ix + 1][jx - 1] + 2 : 0;
                }
            }
        }

        return result;
    }

private:
    void GetPartition(std::vector<std::vector<std::string>>& result, const std::vector<std::vector<int>>& matrix, const std::string& s, int pos, int length) {
        if (pos == s.length()) {
            return;
        }

        result.push_back(std::vector<std::string>());
        result.back().push_back(s.substr(pos, length));
        GetPartition(result, matrix, s, )

    }
};

int main() {
    Solution s;

    std::string str = "aabaa";
    auto result = s.partition(str);

    std::cout << "{ ";
    for (int ix = 0; ix < result.size(); ++ix) {
        auto item = result[ix];
        std::cout << "{ ";
        for (int jx = 0; jx < item.size(); ++jx) {
            std::cout << item[jx] << " ";
        }
        std::cout << " }, ";
    }
    std::cout << " }" << std::endl;
}