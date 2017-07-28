#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows == 0 || numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        vector<string> svector(numRows);
        int one_loop_bound = 2 * numRows - 2;

        for(int ix = 0; ix < s.length(); ++ix) {
            int trans_index = ix % one_loop_bound;
            if (trans_index >= numRows) {
                trans_index = abs(trans_index % (numRows - 1) - numRows + 1);   // reverse the index
            }
            svector[trans_index].push_back(s[ix]);
        }

        string ret = "";
        for(int ix = 0; ix < svector.size(); ++ix) {
            ret.append(svector[ix]);
        }

        return ret;
    }
};

int main() {
    Solution s;

    string str;
    int numRows;

    std::cout << "Please input a string: " << std::endl;
    std::cin >> str;

    std::cout << "Input a number represent row: " << std::endl;
    std::cin >> numRows;

    string ret = s.convert(str, numRows);
    std::cout << "Result is: " << ret << std::endl;

    return 0;
}
