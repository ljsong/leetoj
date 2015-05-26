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
    bool isSymmetric(TreeNode *root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) {
            return true;
        }

        bool left_symmetric = false, right_symmetric = false;
        if(root->left->val == root->right->val) {
            left_symmetric = isSymmetric(root->left);
            right_symmetric = isSymmetric(root->right);
        }
        
        return left_symmetric && right_symmetric;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new Tree(Node);

    return 0;
}
