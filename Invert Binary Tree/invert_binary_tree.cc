#include <iostream>
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode * invertTree(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }

        if (root->left == NULL && root->right == NULL) {
            return root;
        }

        invertTree(root->left);
        invertTree(root->right);

        TreeNode *tmp = NULL;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};
