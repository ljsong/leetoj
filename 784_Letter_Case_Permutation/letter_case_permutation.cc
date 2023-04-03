#include <vector>
#include <string>
#include <iostream>
#include <cctype>

class Solution {
public:
    std::vector<std::string> letterCasePermutation(std::string s) {
        std::vector<std::string> ans;

        if (s.empty()) {
            return ans;
        }

        capitalize(s, ans, 0);
        return ans;
    }

private:
    void capitalize(std::string& s, std::vector<std::string>& ans, int idx) {
        if (idx == s.length()) {
            ans.push_back(s);
            return;
        }

        if (isalpha(s[idx])) {
            s[idx] ^= 0x20;
            capitalize(s, ans, idx + 1);
            s[idx] ^= 0x20;
            capitalize(s, ans, idx + 1);
        } else {
            capitalize(s, ans, idx + 1);
        }
    }
};

int main() {
    Solution s;
    std::string str;

    std::cout << "Input a string: ";
    std::cin >> str;

    std::cout << "str = " << str << std::endl;

    std::vector<std::string> strs = s.letterCasePermutation(str);
    for (const auto& val : strs) {
        std::cout << val << std::endl;
    }

    return 0;
}
