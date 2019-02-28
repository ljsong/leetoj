#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }

    }

};

int main() {
    Solution s;
    string str;
    std::cout << "Input an string: " << std::endl;
    std::cin >> str;

    std::cout << "Longest palindromic substring is: " << std::endl;
    std::cout << s.longestPalindrome(str) << std::endl;;

    return 0;
}
