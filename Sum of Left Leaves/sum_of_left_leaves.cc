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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL || root->left == NULL) {
            return 0;
        }

        vector<TreeNode*> stak;
        int sum = 0;
        stak.push_back(root);

        while(!stak.empty()) {
            TreeNode* node = stak.back();
            stak.pop_back();

            if (node->right != NULL) {
                stak.push_back(node->right);
            }

            if (node->left != NULL) {
                stak.push_back(node->left);
                if (node->left->left == NULL && node->left->right == NULL)
                    sum += node->left->val;
            }
        }

        return sum;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);

    std::cout << s.sumOfLeftLeaves(root) << std::endl;

    return 0;
}
