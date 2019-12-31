#include <iostream>
#include <string>
#include <cctype>
#include <cstdint>

using namespace std;

class Solution {
private:
    inline bool isSign(char ch) {
        return ch == '+' || ch == '-';
    }

    int transform(string str, bool sign) {
        unsigned int sum = 0;
        int bound = INT32_MAX / 10;
        int nmax_digit = -(INT32_MIN % 10), pmax_digit = INT32_MAX % 10;

        for (int ix = 0; ix < str.length(); ++ix) {
            int digit = str[ix] - '0';
            if (sign && (sum > bound || (sum == bound && digit > nmax_digit)))
                return INT32_MIN;
            if (!sign && (sum > bound || (sum == bound && digit > pmax_digit)))
                return INT32_MAX;
            sum = sum * 10 + digit;
        }

        return sign ? -sum : sum;
    }

public:
    int myAtoi(string str) {
        int pos = 0;
        bool negative = false;
        string num;

        // omit extra spaces
        for (;pos < str.length() && isspace(str[pos]); ++pos) {}
        // get the sign
        if (isSign(str[pos])) {
            negative = str[pos] == '-' ? true : false;
            ++pos;
        }
        // collect valid digits as many as possible
        for(; pos < str.length() && isdigit(str[pos]); ++pos) {
            num += str[pos];
        }

        return transform(num, negative);
    }
};

int main() {
    string str;
    std::cout << "Input a string: ";
    std::cin >> str;

    Solution s;
    std::cout << s.myAtoi(str) << std::endl;

    return 0;
}
