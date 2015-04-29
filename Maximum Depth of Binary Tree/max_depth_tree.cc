#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL) {
            return 0;
        } else if(root->left == NULL && root->right == NULL) {
            return 1;
        } else {
            int left_depth = maxDepth(root->left);
            int right_depth = maxDepth(root->right);

            return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
        }
};

int main() {
    Solution s;

    return 0;
}
