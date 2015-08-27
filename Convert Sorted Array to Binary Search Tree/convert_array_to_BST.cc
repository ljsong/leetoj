#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode * sortedArrayToBST(vector<int>& nums) {
        if (nums.size() <= 0) {
            return NULL;
        }
        
        return convertArrayToBST(nums);
    }

private:
    TreeNode * convertArrayToBST(const vector<int>& nums) {
        int n = nums.size();
        int pivot = n >> 1;

        TreeNode *root = new TreeNode(nums[pivot]);
        
        if (pivot > 0) {
            vector<int> left_half(&nums[0], &nums[pivot]);
            root->left = convertArrayToBST(left_half);
        } else {
            root->left = NULL;
        }

        if (pivot < n - 1) {
            vector<int> right_half(&nums[pivot + 1], &nums[n]);
            root->right = convertArrayToBST(right_half);
        } else {
            root->right = NULL;
        }

        return root;
    }
};
