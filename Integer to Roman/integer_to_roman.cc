#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char* matrix[][10] = { {"", "M", "MM", "MMM"},
                                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}};

        int divider = 1000, ix = 0;
        string num_str;

        while(num != 0) {
            int tmp = num / divider;
            num_str += matrix[ix][tmp];

            num = num % divider;
            divider /= 10;
            ++ix;
        }

        return num_str;
    }
};

int main() {
    Solution s;
    int n;
    std::cin >> n;
    std::cout << s.intToRoman(n) << std::endl;

    return 0;
}
