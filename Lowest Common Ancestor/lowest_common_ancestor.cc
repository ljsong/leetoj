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
        if(root == NULL || p == NULL || q == NULL) {
            return NULL;
        }
        
        if(p->left == q || p->right == q) {
            return p;
        }

        if(q->left == p || q->right == p) {
            return q;
        }

        deque<TreeNode *> stak;
        stak.push_back(root);

        while(!stak.empty()) {
            TreeNode *node = stak.back();
            stak.pop_back();

            if(node->left == p || node->right == p || node->left == q || node->right == q) {
                return node;
            }

            if(node->right != NULL) {
                stak.push_back(node->right);
            }

            if(node->left != NULL) {
                stak.push_back(node->left);
            }
        }

        return NULL;

    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(5);
    TreeNode *left = new TreeNode(3);
    TreeNode *right = new TreeNode(4);

    left->left = new TreeNode(7);
    left->right = new TreeNode(9);

    root->left = left;
    root->right = right;

    TreeNode *p = s.lowestCommonAncestor(root, left->right, left->left);
    std::cout << p->val << std::endl;

    return 0;
}
