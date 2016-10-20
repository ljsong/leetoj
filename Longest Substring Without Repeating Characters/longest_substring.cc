#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        int* next = new int[length];
        int k = -1, j = 0;

        next[0] = -1;
        while(j < length - 1) {
            if (k == -1 || s[j] == s[k]) {
                ++k;
                ++j;
                if (s[j] != s[k]) {
                    next[j] = k;
                } else {
                    next[j] = next[k];
                }
            } else {
                k = next[k];
            }
        }

        for (int ix = 0; ix < length; ++ix) {
            std::cout << next[ix] << " ";
        }
        std::cout << std::endl;
        delete[] next;

        return 0;
    }
};

int main() {
    Solution s;
    string str;
    std::cout << "Input a string:" << std::endl;

    std::cin >> str;
    s.lengthOfLongestSubstring(str);

    return 0;
}
