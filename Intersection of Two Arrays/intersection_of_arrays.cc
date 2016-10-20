#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> counts;
        vector<int> ins;

        for(auto itr : nums1) {
            counts[itr] = false;
        }

        for(auto itr : nums2) {
            if (counts.find(itr) != counts.end() && !counts[itr]) {
                counts[itr] = true;
                ins.push_back(itr);
            }
        }

        return ins;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 3, 5, 7, 1, 9};
    vector<int> nums2 = {3, 5};

    vector<int> result = s.intersection(nums1, nums2);
    for(auto itr : result) {
        std::cout << itr << " ";
    }
    std::cout << std::endl;
}
