#include <string>
#include <iostream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        if (s.empty()) {
            return s;
        }

        int ix = 0, jx = 0, len = s.length();
        char temp = 0;
        while (ix < len) {
            for (jx = ix; jx < len && s[jx] != ' '; ++jx) {}
            for (int left = ix, right = jx - 1; left < right; ++left, --right) {
                temp = s[left];
                s[left] = s[right];
                s[right] = temp;
            }
            ix = jx + 1;
        }

        return s;
    }
};

int main() {
    Solution s;
    std::string str = "this";

    std::cout << s.reverseWords(str) << std::endl;
    return 0;
}
