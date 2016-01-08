#include <iostream>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode *q) {
        if (root == NULL || p == NULL || q == NULL) {
            return NULL;
        }

        if (p == root || q == root) {
            return p == root ? p : q;
        }

        if ((p->val < root->val && q->val > root->val) ||
                (p->val > root->val && q->val < root->val)) {
            return root;
        }
        else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

int main() {
    Solution s;
    
    TreeNode *root = new TreeNode(7);
    TreeNode *left = new TreeNode(5);
    TreeNode *right = new TreeNode(9);

    left->left = new TreeNode(3);
    left->right = new TreeNode(6);

    right->left = new TreeNode(10);

    root->left = left;
    root->right = right;

    TreeNode *result = s.lowestCommonAncestor(root, left->left, right);
    std::cout << "Result: " << result->val << std::endl;

    return 0;
}
