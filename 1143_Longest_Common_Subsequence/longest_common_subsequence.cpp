#include <string>
#include <iostream>
#include <vector>

/**
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 * 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 */

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        if (text1.empty() || text2.empty()) {
            return 0;
        } else if (text1 == text2) {
            return text1.length();
        }

        std::vector<std::vector<int>> matrix;
        for (int ix = 0; ix <= text1.length(); ++ix) {
            matrix.push_back(std::vector<int>(text2.length() + 1, 0));
        }

        // initial state: "" with ""#P, from 0 to text2.length() + 1 are:
        // "" with "", "" with P[0..<1], "" with P[0..<2], etc.
        for (int ix = 1; ix <= text1.length(); ++ix) {
            for (int jx = 1; jx <= text2.length(); ++jx) {
                matrix[ix][jx] = std::max({
                    matrix[ix - 1][jx - 1] + static_cast<int>(text1[ix - 1] == text2[jx - 1]),
                    matrix[ix - 1][jx], matrix[ix][jx - 1]
                });
            }
        }

        return matrix[text1.length()][text2.length()];
    }
};

int main() {
    Solution s;
    std::cout << s.longestCommonSubsequence("aaaaaa", "aaaaaa");
    return 0;
}