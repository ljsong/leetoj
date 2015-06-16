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
    int sumNumbers(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }            

        vector<TreeNode *> stak;
        stak.push_back(root);
        int total_sum = 0;

        while(!stak.empyt()) {
            TreeNode *node = stak.back();
            stak.pop_back();
            
            if(node->left == NULL && node->right == NULL) {
                total_sum += node->val;
            } else {
                if(node->right != NULL) {
                    stak.push_back(node->right);
                }

                if(node->left != NULL) {
                    stak.push_back(node->left);
                }
            }

    }
};

int main() {
    Solution s;

    return 0;
}
