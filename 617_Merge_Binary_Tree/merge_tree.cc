#include <iostream>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        } else if (root2 == nullptr) {
            return root1;
        }

        TreeNode* root = nullptr;
        merge_tree_nodes(root, root1, root2);

        return root;
    }

    TreeNode* merge_tree_nodes(TreeNode*& root, TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }

        if (root1 != nullptr && root2 != nullptr) {
            root = new TreeNode(root1->val + root2->val, nullptr, nullptr);
            merge_tree_nodes(root->left, root1->left, root2->left);
            merge_tree_nodes(root->right, root1->right, root2->right);
        } else if (root1 == nullptr) {
            root = new TreeNode(root2->val, nullptr, nullptr);
            merge_tree_nodes(root->left, nullptr, root2->left);
            merge_tree_nodes(root->right, nullptr, root2->right);
        } else if (root2 == nullptr) {
            root = new TreeNode(root1->val, nullptr, nullptr);
            merge_tree_nodes(root->left, root1->left, nullptr);
            merge_tree_nodes(root->right, root1->right, nullptr);
        }

        return root;
    }
};

void printTreeNode(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printTreeNode(root->left);
    std::cout << root->val << " ";
    printTreeNode(root->right);
}

int main() {
    Solution s;

    TreeNode *root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode *root2 = new TreeNode(4, new TreeNode(5), new TreeNode(6));
    TreeNode *root = s.mergeTrees(root1, root2);

    printTreeNode(root);
    return 0;
}
