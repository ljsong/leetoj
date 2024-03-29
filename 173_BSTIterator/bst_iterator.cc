#include <iostream>
#include <vector>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode *cur = root;
        // go to the left most node
        while(cur != nullptr) {
            chain.push_back(cur);
            cur = cur->left;
        }
    }
    
    int next() {
        TreeNode* cur = chain.back();
        int ret_val = cur->val;
        chain.pop_back();
        if (cur->right != nullptr) {
            cur = cur->right;
            while(cur != nullptr) {     // traverse the right sibling
                chain.push_back(cur);
                cur = cur->left;
            }
        }

        return ret_val;
    }
    
    bool hasNext() {
        return !chain.empty();
    }

private:
    std::vector<TreeNode*> chain;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    TreeNode* root = new TreeNode(7);
    // root->left = new TreeNode(3, nullptr, nullptr);
    // root->right = new TreeNode(15, new TreeNode(9, nullptr, nullptr), new TreeNode(20, nullptr, nullptr));

    BSTIterator itr(root);
    std::cout << itr.next() << std::endl;
    // std::cout << itr.next() << std::endl;
    std::cout << itr.hasNext() << std::endl;
    // std::cout << itr.next() << std::endl;
    // std::cout << itr.hasNext() << std::endl;
    // std::cout << itr.next() << std::endl;
    // std::cout << itr.hasNext() << std::endl;
    // std::cout << itr.next() << std::endl;
    // std::cout << itr.hasNext() << std::endl;

    return 0;
}
