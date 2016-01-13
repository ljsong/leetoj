/* Given an integer, write a function to determine if it is a power of two.
 *
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }

        return (!(n & (n - 1)));
    }
};

int main() {
    Solution s;
    int num;
    std::cin >> num;
    std::cout << num << " is" << (s.isPowerOfTwo(num) ? " " : " not ") << "power of 2" << std::endl;

    return 0;
}
