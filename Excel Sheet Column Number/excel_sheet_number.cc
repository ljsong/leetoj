#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;

        for(int ix = 0; ix < s.length(); ++ix) {
            int n = s[ix] - 'A' + 1;
            sum = sum * 26 + n;
        }

        return sum;
    }
};

int main() {
    Solution s;
    std::string str;
    std::cin >> str;

    std::cout << s.titleToNumber(str) << std::endl;

    return 0;
}
