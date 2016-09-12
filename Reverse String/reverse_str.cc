#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string reversed_string = s;
        int size = s.length();

        if (size <= 1) {
            return s;
        }

        for(int ix = size - 1; ix >= 0; --ix) {
            reversed_string[size - 1 - ix] = s[ix];
        }

        return reversed_string;
    }
};

int main() {
    Solution s;
    string str;
    std::cout << "Input an string:" << std::endl;
    std::cin >> str;

    std::cout << "Reversed String: " << s.reverseString(str) << std::endl;

    return 0;
}
