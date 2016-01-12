#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        long result = 0;
        int mod_result = 0;
        set<int> occured;

        long num = n;
        while(num != 1) {
            result = 0;
            while (num != 0) {
                mod_result = num % 10;
                num = num / 10; 
                result += (mod_result * mod_result);
            }
            num = result;
            if (occured.find(result) != occured.end()) {
                break;
            } else {
                occured.insert(result);
            }
        }

        return (num == 1);
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
