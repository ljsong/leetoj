#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int count = digits.size();
        int carry = 1, result = 0;

        for(int ix = count - 1; ix >= 0; --ix) {
            result = digits[ix] + carry; 
            digits[ix] = result % 10;
            carry = result / 10; 
        }

        if(carry == 1) {
            shift_right(digits);
        }

        return digits;
    }

private:
    void shift_right(vector<int>& digits) {
        int count = digits.size();

        digits.push_back(digits[count - 1]);
        for(int ix = 0; ix < count - 1; ++ix) {
            digits[ix + 1] = digits[ix];
        }
        digits[0] = 1;
    }
};

int main() {
    Solution s;
    int a[] = {9};
    vector<int> nums(&a[0], &a[0] + 1);

    vector<int> ivec = s.plusOne(nums);
    for(int ix = 0; ix < ivec.size(); ++ix) {
        std::cout << ivec[ix];
    }
    std::cout << std::endl;

    return 0;
}
