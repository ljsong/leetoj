#include <string>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;

        if (digits.empty()) {
            return ret;
        }

        if (digits.find('1') != string::npos || digits.find('0') != string::npos) {
            return ret;
        }

        char* letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        deque<string> stak;
        int index = 1;

        string symbols = letters[digits[0] - '0'];
        for(int ix = 0; ix < symbols.length(); ++ix) {
            stak.push_back(string(1, symbols[ix]));
        }
        stak.push_back("#");        // when encounter this symbol, we should move the indicator right

        while(!stak.empty()) {
            string str = stak.front();
            stak.pop_front();

            if (stak.empty()) {
                break;
            } else if (str == "#") {
                stak.push_back("#");
                ++index;
                continue;
            } else if (str.length() == digits.length()) {
                ret.push_back(str);
                continue;
            }

            symbols = letters[digits[index] - '0'];
            for(int jx = 0; jx < symbols.length(); ++jx) {
                stak.push_back(str + symbols[jx]);
            }
        }

        return ret;
    }
};

int main() {
    Solution s;

    string str;
    std::cout << "Please input a number: " << std::endl;
    std::cin >> str;

    vector<string> ret = s.letterCombinations(str);
    for(int ix = 0; ix < ret.size(); ++ix) {
        std::cout << ret[ix] << ", ";
    }

    return 0;
}
