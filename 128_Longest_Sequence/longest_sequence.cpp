#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>

/**
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 */
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_map<int, int> hash, count;

        for(auto num : nums) {
            hash[num] = num;
            count[num] = 1;
        }

        for (auto num : nums) {
            if (hash.count(num - 1)) {
                Union(hash, count, num, num - 1);
            } else if (hash.count(num + 1)) {
                Union(hash, count, num + 1, num);
            }
        }

        int max_length = 0;
        for (const auto& [_, v] : count) {
            max_length = max_length > v ? max_length : v;
        }

        return max_length;
    }

    void Union(std::unordered_map<int, int>& hash, std::unordered_map<int, int>& count, int a, int b) {
        a = Find(hash, a);
        b = Find(hash, b);
        if (a == b) {
            return;
        }

        // make the tree balanced
        if (count[a] > count[b]) {
            hash[b] = a;
            count[a] += count[b];
        } else {
            hash[a] = b;
            count[b] += count[a];
        }
    }

    // using path compressing
    int Find(std::unordered_map<int, int>& hash, int a) {
        return hash[a] == a ? a : hash[a] = Find(hash, hash[a]);
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {0, 3, 9, 7, 4, 1, 2, 6, 8, 5};
    std::cout << s.longestConsecutive(nums) << std::endl;

    return 0;
}