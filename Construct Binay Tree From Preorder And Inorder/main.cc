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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = nullptr;

        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
            return root;
        }

        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
private:
    TreeNode* build(const std::vector<int>& preorder, int pstart, int pend,
                std::vector<int>& inorder, int istart, int iend) {
        if (pstart == pend || istart == iend) {
            return nullptr;
        }

        int val = preorder[pstart];
        TreeNode* root = new TreeNode(val);

        int left_end = istart;
        for (; left_end < iend && inorder[left_end] != val; ++left_end) {}
        int left_count = left_end - istart;

        root->left = build(preorder, pstart + 1, pstart + 1 + left_count,
                           inorder, istart, left_end);
        root->right = build(preorder, pstart + 1 + left_count, pend,
                            inorder, left_end + 1, iend);

        return root;
    }
};
