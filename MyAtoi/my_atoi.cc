#include <iostream>
#include <string>
#include <numeric_limits>

class Solution {
public:
    Solution()
        : MAX_INTEGER(std::numeric_limits<int>::max())
        , MIN_INTEGER(std::numeric_limits<int>::min()) {
        MAX_QUOTIENT = MAX_INTEGER / 10;
        MAX_REMAINDER = MAX_INTEGER % 10;

        MIN_QUOTIENT = -(MIN_INTEGER / 10);
        MIN_REMAINDER = -(MIN_INTEGER % 10);
    }

    int myAtoi(std::string s) {
        int s_pos = 0;
        bool positive = true;

        for (; s[s_pos] == ' ' && s_pos < s.length(); ++s_pos) {}

        if (s[s_pos] == '-') {
            positive = false;
            ++s_pos;
        } else if (s[s_pos] == '+') {
            positive = true;
            ++s_pos;
        }

        int32_t num = 0;
        while(s[s_pos] >= '0' && s[s_pos] <= '9') {
            int32_t cur_digit = s[s_pos] - '0';
            if (positive && (MAX_QUOTIENT < num ||
                        MAX_QUOTIENT == num && MAX_REMAINDER <= cur_digit)) {
                return MAX_INTEGER;
            }

            if (!positive && (MIN_QUOTIENT < num ||
                        MIN_QUOTIENT == num && MIN_REMAINDER <= cur_digit)) {
                return MIN_INTEGER;
            }

            num = num * 10 + cur_digit;
            s_pos++;
        }

        return positive ? num : -num;
    }

private:
    const int32_t MAX_INTEGER, MIN_INTEGER;
    int32_t MAX_QUOTIENT, MAX_REMAINDER;
    int32_t MIN_QUOTIENT, MIN_REMAINDER;
};

int main() {
    Solution s;
    std::string str;

    std::cin >> str;
    std::cout << s.myAtoi(str) << std::endl;

    return 0;
}
