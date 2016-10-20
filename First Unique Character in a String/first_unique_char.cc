#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        int index[26] = {0}, count[26] = {0};
        int len = s.length();
        
        if (len == 0) {
            return -1;
        } else if (len == 1) {
            return 0;
        }

        for (int ix = 0; ix < len; ++ix) {
            ++count[s[ix] - 'a'];
            index[s[ix] - 'a'] = count[s[ix] - 'a'] == 1 ? ix : 0;
        }

        for (int ix = 0; ix < len; ++ix) {
            if (count[s[ix] - 'a'] == 1) {
                return index[s[ix] - 'a'];
            }
        }
        
        return -1;
    }
};

int main() {
    Solution s;
    string str;

    std::cout << "Input a string: " << std::endl;
    std::cin >> str;

    std::cout << s.firstUniqChar(str) << std::endl;

    return 0;
}
