#include <vector>
#include <iostream>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int len = nums.size();
        if (k >= len) {
            k = k % len;
        }

        if (k == 0 || nums.empty()) {
            return;
        }

        int groups = gcd(len, k);
        int count = 0, group_idx = 0, group_len = len / groups;
        int cur_num, next_num;

        while (group_idx < groups) {
            count = 0, cur_num = nums[group_idx];
            for (int ix = group_idx; count < group_len; ++count) {
                ix = (ix + k) % len;
                next_num = nums[ix];
                nums[ix] = cur_num;
                cur_num = next_num;
            }
            ++group_idx;
        }
    }

private:
    int gcd(int a, int b) {
        int r;

        while(b > 0) {
            r = a % b;
            a = b;
            b = r;
        }

        return a;
    }
};


int main() {
    Solution s;
    int k;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    std::cout << "Input k: ";
    std::cin >> k;

    s.rotate(nums, k);

    for (const auto& val : nums) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
