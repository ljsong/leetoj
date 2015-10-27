#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int result = 0;
        int mod_result = 0;
        while (n != 0) {
            mod_result = n % 10;
            n = n / 10; 
            result += (mod_result * mod_result) % 9;
        }

        return (result % 9 == 1);
    }
};

int main() {
    std::cout << "Input a number: ";
    int n;
    Solution s;
    std::cin >> n;

    std::cout << (s.isHappy(n) ? "true" : "false") << std::endl;

    return 0;
}
