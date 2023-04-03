#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > matrix;
        vector<int> nums;

        if(n == 0 || k == 0) {
            return matrix;
        }

        get_solution(1, k, n, nums, matrix);
        return matrix;
    }

private:
    void get_solution(int ix, int k, int n, vector<int>& nums, vector<vector<int> >& matrix) {
        if(nums.size() >= k) {
            matrix.push_back(nums);
            return ;
        }
        
        for(; ix <= n; ++ix) {
            nums.push_back(ix);
            get_solution(ix + 1, k, n, nums, matrix);
            nums.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<int> > matrix = s.combine(5, 2);

    for(int ix = 0; ix < matrix.size(); ++ix) {
        for(int jx = 0; jx < matrix[ix].size(); ++jx) {
            std::cout << matrix[ix][jx] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
