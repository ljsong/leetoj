#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ret;

        if (s.empty()) {
            return ret;
        }

        int ix = 0;
        int count = 0;

        while(ix < s.length()) {
            char ch = s[ix];
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
                ret.push_back(ch);
            } else if (ch >= '0' && ch <= '9') {
                int bracket = 0;
                string part;
                count = count * 10 + ch - '0';

                if (s[ix + 1] != '[') {
                    ++ix;
                    continue;
                }

                do {
                    ++ix;
                    if (s[ix] == '[') {
                        ++bracket;
                        part.push_back('[');
                    } else if (s[ix] == ']') {
                        --bracket;
                        part.push_back(']');
                    } else {
                        part.push_back(s[ix]);
                    }
                } while(bracket != 0);
                
                while(count > 0) {
                    ret += decodeString(part);
                    --count;
                }
            }

            ++ix;
        }

        return ret;
    }
};

int main() {
    Solution s;
    string str;

    std::cout << "Input a string: " << std::endl;
    std::cin >> str;

    std::cout << "Result is: " << s.decodeString(str) << std::endl;
    return 0;
}
