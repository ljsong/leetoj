#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stak;
        map<char, char> expected_char;
        int len = s.length();
        int ix = 0;

        expected_char['('] = ')';
        expected_char['['] = ']';
        expected_char['{'] = '}';

        while(ix < len) {
            if (s[ix] == '(' || s[ix] == '[' || s[ix] == '{') {
                stak.push_back(s[ix]);
            } else if (!stak.empty() && expected_char[stak.back()] == s[ix]){
                stak.pop_back();
            } else {
                return false;
            }
            ++ix;
        }

        return stak.empty();
    }
};

int main() {
    Solution s;
    string str;

    std::cout << "Input a string: " << std::endl;
    std::cin >> str;

    std::cout << "Is valid: " << (s.isValid(str) ? "YES" : "NO") << std::endl;

    return 0;
}
