#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return (1 + (num - 1) % 9);
    }
};

int main() {
    Solution s;
    int n;
    std::cin >> n;
    std::cout << s.addDigits(n) << std::endl;

    return 0;
}
