#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int kx = 0, length = nums.size();
        for (int ix = 0; ix < length; ++ix) {
            if (nums[ix] == 0) {
                ++kx;
            } else {
                nums[ix - kx] = nums[ix];
            }
        }

        for (int ix = length - 1; ix > length - 1 - kx; --ix) {
            nums[ix] = 0;
        }
    }
};

int main() {
    Solution s;
    int array[] = {1, 0, 5, 3, 0, 9, 10, 3, 0, 7, 6};
    vector<int> v(&array[0], &array[0] + 11);
    s.moveZeroes(v);

    for (int ix = 0; ix < v.size(); ++ix) {
        std::cout << v[ix] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
