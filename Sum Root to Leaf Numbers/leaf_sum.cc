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

        int partial_sum = 0, total_sum = 0;
        compute_sum(root, partial_sum, total_sum);

        return total_sum;
    }

private:
    void compute_sum(TreeNode *node, int& partial_sum, int& total_sum) {
        partial_sum = partial_sum * 10 + node->val;

        if(node->left == NULL && node->right == NULL) {
            total_sum += partial_sum;
        }

        if(node->left != NULL) {
            compute_sum(node->left, partial_sum, total_sum);
            partial_sum /= 10;
        }

        if(node->right != NULL) {
            compute_sum(node->right, partial_sum, total_sum);
            partial_sum /= 10;
        }
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::cout << s.sumNumbers(root) << std::endl;
    return 0;
}
