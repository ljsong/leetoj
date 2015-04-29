#include <iostream>
using namespace std;
typedef unsigned int uint32_t; 

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n != 0) {
            ++count;
            n &= (n - 1);
        }

        return count;
    }
};


int main() {
    Solution s;
    int n;
    std::cin >> n;
    std::cout << s.hammingWeight(n) << std::endl;

    return 0;
}

