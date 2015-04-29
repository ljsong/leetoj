#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, num = nums[0];

        for(int ix = 1; ix < nums.size(); ++ix) {
            if(num != nums[ix]) {
                --count;    // if the recorded number is not equal to the current element in vector
                num = (count == 0 ? nums[ix] : num);  // then minus the counter, change the recorded number
                count = (count == 0 ? 1 : count);   // to the current element and reset the counter
            } else {
                ++count;
            }
        }  // after doing the loop the num record the number that occur more than half times

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
