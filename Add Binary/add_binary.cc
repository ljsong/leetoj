#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, half_sum = 0;
        int ix = a.length() - 1, jx = b.length() - 1;
        string sum;
        for (; ix >= 0 && jx >= 0; --ix, --jx) {
            add_binary(a[ix] - 0x30, b[jx] - 0x30, carry, half_sum);
            sum.insert(sum.begin(), half_sum + 0x30);
        }

        while(ix >= 0) {
            add_binary(a[ix--] - 0x30, 0, carry, half_sum);
            sum.insert(sum.begin(), half_sum + 0x30);
        }

        while(jx >= 0) {
            add_binary(b[jx--] - 0x30, 0, carry, half_sum);
            sum.insert(sum.begin(), half_sum + 0x30);
        }

        if (carry) {
            sum.insert(sum.begin(), '1');
        }

        return sum;
    }

private:
    void add_binary(int a, int b, int& carry, int& sum) {
        sum = a ^ b ^ carry;
        carry = (a & b) | (carry & (a ^ b));
    }
};

int main() {
    std::string first, second;
    std::cout << "Please input first string: " << std::endl;
    std::cin >> first;

    std::cout << "Please input another string: " << std::endl;
    std::cin >> second;

    Solution s;
    std::cout << "Answer is: " << s.addBinary(first, second) << std::endl;
    return 0;
}
