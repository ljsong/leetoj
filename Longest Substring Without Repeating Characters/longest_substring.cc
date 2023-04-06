#include <string>
#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int left = 0, right = 0;
        int max_len = 0;
        std::vector<int> dict(128, -1);

        for (int right = 0; right < s.size();) {
            unsigned char ch = s[right];
            if (dict[ch]++ != -1) {
                left = left > dict[ch] ? left : dict[ch];
            }
            dict[ch] = right++;
            max_len = max_len > right - left? max_len : right - left;
        }
        return max_len;
    }
};

int main() {
    std::string str;
    std::cout << "Input a string:" << std::endl;

    std::cin >> str;
    std::cout << s.lengthOfLongestSubstring(str) << std::endl;


    return 0;
}
