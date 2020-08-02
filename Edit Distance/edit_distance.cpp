#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) {
            return word2.length();
        } else if (word2.empty()) {
            return word1.length();
        }

        int len1 = word1.length();
        int len2 = word2.length();
        int **dp = new int*[len1 + 1];
        for(int ix = 0; ix <= len1; ++ix) {
            dp[ix] = new int[len2 + 1];
        }

        for (int ix = 0; ix <= len1; ++ix) {
            dp[ix][0] = ix;
        }

        for (int ix = 0; ix <= len2; ++ix) {
            dp[0][ix] = ix;
        }

        for (int ix = 0; ix < len1; ++ix) {
            for (int jx = 0; jx < len2; ++jx) {
                if (word1[ix] == word2[jx]) {
                    dp[ix + 1][jx + 1] = dp[ix][jx];
                } else {
                    dp[ix + 1][jx + 1] = std::min({dp[ix + 1][jx] + 1, dp[ix][jx + 1] + 1, dp[ix][jx] + 1});
                }
            }
        }

        int ret = dp[len1][len2];
        for (int ix = 0; ix <= len1; ++ix) {
            delete[] dp[ix];
            dp[ix] = nullptr;
        }
        delete[] dp;

        return ret;
    }
};

int main() {
    Solution s;
    std::string first = "Hello", second = "halo";
    std::cout << s.minDistance(first, second) << std::endl;

    return 0;
}
