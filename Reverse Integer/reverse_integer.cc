#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        const int MAX = (int)((unsigned)~0 >> 1);
        const int MIN = (-MAX - 1);
        int sum = 0; 

        while(x != 0) {
            int n = x % 10;
            x /= 10;
            
            if(sum > MAX / 10 || sum < MIN / 10) {
                return 0;
            }
            sum = sum * 10 + n;
        }

        return sum;
    }
};

int main() {
    Solution s;
    int n = 0;
    std::cin >> n;
    std::cout << s.reverse(n) << std::endl;

    return 0;
}
