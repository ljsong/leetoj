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
