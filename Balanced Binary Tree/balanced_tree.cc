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
    bool isBalanced(TreeNode *root) {
        int depth = 0;

        return Height(root, depth);
    }

private:
    bool Height(TreeNode *node, int &depth) {
        if(node == NULL) {
            depth = 0;
            return true;
        } else if(node->left == NULL && node->right == NULL) {
            depth = 1;
            return true;
        }

        int left_height = 0, right_height = 0;
        if (Height(node->left, left_height) && Height(node->right, right_height)) {
            int diff = left_height - right_height;
            if(diff <= 1 && diff >= -1) {
                depth = left_height > right_height ? left_height + 1 : right_height + 1;
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    return 0;
}
