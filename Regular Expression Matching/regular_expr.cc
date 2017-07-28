#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p == s || p == ".*") {
            return true;
        }

        if (s.empty() || p.empty()) {
            return false;
        }

        char last_char;
        int ix = 0, jx = 0;

        for(; ix < s.length(), jx < p.length(); ++ix) {
            if (s[ix] != p[jx] && p[jx] != '*' && p[jx] != '.') {   
                if (jx + 1 < p.length() && p[jx + 1] == '*') {          // s = "aaaa", p = "cccc"
                    jx += 2;
                    --ix;
                    continue;
                } else {        // s = "aaaa", p = "c*aaa"
                    return false;
                }
            } else if (s[ix] == p[jx] || p[jx] == '.') {        // s = "aaa", p = "aaa" or "..."
                last_char = p[jx++];
                continue;
            } else if (p[jx] == '*') {
                if (last_char == s[ix] || last_char == '.') {
                    continue;           // stay here, wait next char in s
                } else {
                    ++jx;               // next char in p
                    --ix;
                    continue;
                }
            }
        }

        if (ix < s.length() || jx < p.length()) {
            return false;
        } 

        return true;
    }
};

int main() {
    Solution s;

    string str, pattern;

    std::cout << "Input a string: " << std::endl;
    std::cin >> str;

    std::cout << "Input a pattern: " << std::endl;
    std::cin >> pattern;

    std::cout << "Result is: " << s.isMatch(str, pattern) << std::endl;

    return 0;
} 

