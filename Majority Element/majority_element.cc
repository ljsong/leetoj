#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, num = nums[0];

        for(int ix = 1; ix < nums.size(); ++ix) {
            if(num != nums[ix]) {
                --count;
                num = (count == 0 ? nums[ix] : num);
                count = (count == 0 ? 1 : count);
            } else {
                ++count;
            }
        }

        return num;
    }
};

int main() {
    Solution s;
    int array[] = {1, 2, 3, 2, 2};
    vector<int> ivec(&array[0], &array[0] + 5);

    std::cout << s.majorityElement(ivec) << std::endl;

    return 0;
}
