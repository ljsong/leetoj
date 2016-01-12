#include <iostream>
using namespace std;

class Solution{
public:
    bool isUgly(int num) {
        if (num == 1 || num == 0) {
            return num;
        }

        for(int ix = 2; ix <= 5; ++ix) {
            while(num != ix) {
                if (num % ix == 0) {
                    num /= ix;
                } else {
                    break;
                }
            }
        }

        return (num == 2 || num == 3 || num == 5);
    }
};

int main() {
    Solution s;
    int n;
    std::cin >> n;
    std::cout << (s.isUgly(n) ? "Ugly" : "Not Ugly") << std::endl;

    return 0;
}
