#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > matrix;
        permute(matrix, nums, nums.size());

        return matrix;
    }

private:
    void permute(vector<vector<int> >& matrix, vector<int>& nums, int n) {
        if(n == 1) {
            matrix.push_back(nums);
            return ;
        }

        for(int ix = 0; ix < n; ++ix) {
            swap(nums[ix], nums[n - 1]);
            permute(matrix, nums, n - 1);
            swap(nums[ix], nums[n - 1]);
        }
    }
};

int main() {
    Solution s;
    int a[] = {1, 2, 3};
    vector<int> nums(&a[0], &a[0] + 3);

    vector<vector<int> > matrix = s.permute(nums);
    for(int ix = 0; ix < matrix.size(); ++ix) {
        for(int jx = 0; jx < matrix[ix].size(); ++jx) {
            std::cout << matrix[ix][jx] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
