#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;

        if(nums.size() <= 0) {
            return ret;
        }

        int partial_product = 1;
        ret.push_back(partial_product);
        for(int ix = 1; ix < nums.size(); ++ix) {
            ret.push_back(nums[ix - 1] * partial_product);
            partial_product *= nums[ix - 1];
        }

        partial_product = 1;
        for(int ix = nums.size() - 1; ix >= 0; --ix) {
            ret[ix] *= partial_product;
            partial_product *= nums[ix];
        }
            
        return ret;
    }
};

int main() {
    Solution s;
    int a[] = {7, 0, 3, 4};
    vector<int> nums(&a[0], &a[0] + 4);
    vector<int> result = s.productExceptSelf(nums);

    for(int ix = 0; ix < result.size(); ++ix) {
        std::cout << result[ix] << " ";
    }
    std::cout << std::endl;

    return 0;
}
