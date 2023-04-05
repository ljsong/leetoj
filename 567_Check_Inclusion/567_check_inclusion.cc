#include <iostream>
#include <string>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.empty() || s2.empty()) {
            return false;
        }

        if (s1 == s2) {
            return true;
        }
        
        int left = 0, right = 0;
        std::set<char> chars;
        for (int ix = 0; ix < s1.length(); ++ix) {
            chars.insert(s1[ix]);
        }

        while(right < s2.length()) {
            for (; left < s2.length() && chars.count(s2[left]) == 0;) {
                right = ++left;
            }

            if (chars.count(s2[right]) == 0) {
                left = ++right;
            } else {


    }
};

int main() {
    Solution s;
    std::string s1, s2;

    std::cout << "Input string1: ";
    std::cin >> s1;

    std::cout << "Input string2: ";
    std::cin >> s2;

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;

    std::cout << s.checkInclusion(s1, s2) << std::endl;
    return 0;
}
