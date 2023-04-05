#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for(int ix = 0; ix < nums.size(); ++ix) {
            num ^= nums[ix];
        }

        return num;
    }
};

int main() {
    Solution s;
    int array[] = {2, 2, 5, 6, 1, 7, 6, 5, 1};
    vector<int> ivec(&array[0], &array[9]);
    std::cout << s.singleNumber(ivec) << std::endl;

    return 0;
}
