#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ivec;

        if (nums.empty()) {
            ivec.push_back(vector<int>());
            return ivec;
        }

        vector<int> empty;
        ivec.push_back(empty);
        int size = ivec.size();

        for(auto num : nums) {
            int ix = 0;
            for(; ix < size; ++ix) {
                vector<int> new_set = ivec[ix]; 
                new_set.push_back(num);
                ivec.push_back(new_set);
            }
            size += ix;
        }

        return ivec;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ivec = s.subsets(nums);
    for(auto itr = ivec.begin(); itr != ivec.end(); ++itr) {
        std::cout << "[";
        for(auto sitr = itr->begin(); sitr != itr->end(); ++sitr) {
            std::cout << *sitr << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
