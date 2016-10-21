#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty() && num2.empty()) {
            return "0";
        }

        int carry = 0, len1 = num1.length() - 1, len2 = num2.length() - 1;
        int ix = len1, jx = len2, kx = len1 > len2 ? len1 : len2; 
        string sum(kx + 1, 0);
        for(; ix >= 0 && jx >= 0 ; --ix, --jx) {
            sum[kx] = num1[ix] - '0' + num2[jx] - '0' + carry;
            carry = sum[kx] / 10;
            sum[kx] = sum[kx] % 10 + '0';
            --kx;
        }

        while(ix >= 0) {
            sum[kx] = num1[ix--] - '0' + carry;
            carry = sum[kx] / 10;
            sum[kx] = sum[kx--] % 10 + '0';
        }

        while(jx >= 0) {
            sum[kx] = num2[jx--] - '0' + carry;
            carry = sum[kx] / 10;
            sum[kx] = sum[kx--] % 10 + '0';
        }

        if (carry != 0) {
            return "1" + sum;
        }

        return sum;
    }
};

int main() {
    string num1, num2;
    Solution s;

    std::cout << "Input two strings: " << std::endl;
    std::cin >> num1 >> num2;

    std::cout << "Sum is: " << s.addStrings(num1, num2) << std::endl;
    return 0;
}
