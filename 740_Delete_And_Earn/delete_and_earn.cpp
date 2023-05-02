#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) {
        // this map means the max points from current number we can get
        std::map<int, int> counts;

        for (auto num : nums) {
            counts[num] += num;
        }

        // F(n) = max(F(n - 1), F(n - 2) + nums[n])
        int max_points = 0;
        for (auto iter = counts.begin(); iter != counts.end(); ++iter) {
            auto k = iter->first;
            auto& v = iter->second;

            auto k_1 = counts.find(k - 1);
            auto prev = counts.begin();
            if (k_1 == counts.end()) {
                prev = iter;
                v = iter == counts.begin() ? v : v + (--prev)->second;
            } else {
                prev = k_1;
                auto selected_val = k_1 == counts.begin() ? v : v + (--prev)->second;
                v = selected_val > k_1->second ? selected_val : k_1->second;
            }

            max_points = max_points > v ? max_points : v;
        }

        return max_points;
    }
};

int main() {
    Solution s;
    std::vector<int> nums{1, 2, 6, 3, 9, 5, 5};

    std::cout << s.deleteAndEarn(nums) << std::endl;
}