#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        } else if(x >= 0 && x < 10) {
            return true;
        } else {
            int n = log(x) / log(10) + 1;
            
            for(int ix = n - 1, jx = 0; ix > jx; --ix, ++jx) {
                int leading = (int)(x / pow(10, ix)) % 10;
                int trailing = (int)(x / pow(10, jx)) % 10;

                if(leading != trailing) {
                    return false;
                }
            }

            return true;
        }
    }

};

int main() {
    Solution s;
    std::cout << s.isPalindrome(12345) << std::endl;

    return 0;
}
