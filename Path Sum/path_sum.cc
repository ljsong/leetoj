#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }

        return _has_path_sum(root, sum, 0);
    }

private:
    bool _has_path_sum(TreeNode *root, int sum, int current_sum) {
        bool ret = false;
        current_sum += root->val;

        bool is_leaf = root->left == NULL && root->right == NULL;
        if (current_sum == sum && is_leaf) {
            return true; 
        }

        if (root->left) {
            ret |= _has_path_sum(root->left, sum, current_sum);
        }

        if (root->right) {
            ret |= _has_path_sum(root->right, sum, current_sum);
        }

        current_sum -= root->val;
        return ret;
    }
};

int main() {
    Solution s;

    TreeNode *root = new TreeNode(5);
    TreeNode *left = new TreeNode(7);
    TreeNode *right = new TreeNode(2);

    root->left = left;
    root->right = right;

    left->left = new TreeNode(3);
    left->right = new TreeNode(4);

    right->right = new TreeNode(1);
    std::cout << s.hasPathSum(root, 8) << std::endl;

    return 0;
}
