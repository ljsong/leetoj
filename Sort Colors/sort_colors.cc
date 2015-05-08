#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;

        for(int ix = 0; ix < nums.size(); ++ix) {
            if(nums[ix] == 0) {
                if(nums[zero] == 1 && ix > one) {   //1 does not appear in the deserved place, this will lead to a out-of-sequence
                    swap(nums[zero], nums[one]);
                }
                swap(nums[ix], nums[zero]);
                ++zero;
                ++one;
                ++two;
            } else if(nums[ix] == 1) {
                swap(nums[ix], nums[one]);
                ++one;
                ++two;
            } else if(nums[ix] == 2) {
                swap(nums[ix], nums[two]);
                ++two;
            }
        }
    }

private:
    void swap(int &a, int &b) {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
};

int main() {
    Solution s;
    int a[] = {2, 2, 2, 1, 0, 0, 0, 0};
    vector<int> ivec(&a[0], &a[0] + 7);
    s.sortColors(ivec);

    for(int ix = 0; ix < ivec.size(); ++ix) {
        std::cout << ivec[ix] << " ";
    }
    std::cout << std::endl;

    return 0;
}
