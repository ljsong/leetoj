#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using my_pair_t = std::pair<int, int>;
using my_container_t = std::vector<my_pair_t>;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> statis;
        vector<int> rets;

        for(auto iter = nums.begin(); iter != nums.end(); ++iter) {
            ++statis[*iter];
        }

        auto my_comp = 
            [](const my_pair_t& p1, const my_pair_t& p2)
            { return p1.second < p2.second; };
        priority_queue<my_pair_t, my_container_t, decltype(my_comp)> pqueue(my_comp);
        
        for (auto iter =statis.begin(); iter != statis.end(); ++iter) {
            pqueue.push(*iter);
        }

        int ix = k;
        while(ix > 0) {
            rets.push_back(pqueue.top().first);
            pqueue.pop();
            --ix;
        }

        return rets;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> rets = s.topKFrequent(nums, 2);

    for(int ix = 0; ix < rets.size(); ++ix) {
        std::cout << rets[ix] << " ";
    }
    std::cout << std::endl;
}
