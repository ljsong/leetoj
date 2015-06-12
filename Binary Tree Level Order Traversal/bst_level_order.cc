#include <iostream>
#include <vector>
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > matrix;
        deque<TreeNode*> queue;

        if(root == NULL) {
            return matrix;
        }

        queue.push_back(root);
        while(!queue.empty()) {
            queue.push_back(NULL);      // treat NULL as separator
            TreeNode *node = queue.front();
            vector<int> ivec;
            while(node != NULL) {
                queue.pop_front();
                ivec.push_back(node->val);

                if(node->left) {
                    queue.push_back(node->left);
                }

                if(node->right) {
                    queue.push_back(node->right);
                }

                node = queue.front();
            }
            queue.pop_front();      // pop out the last separator
            matrix.push_back(ivec);
        }
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    TreeNode *left = new TreeNode(9);
    TreeNode *right = new TreeNode(20);

    left->left = new TreeNode(8);
    left->right = new TreeNode(19);

    right->left = new TreeNode(15);
    right->right = new TreeNode(7);

    root->left = left;
    root->right = right;

    vector<vector<int> > matrix = s.levelOrder(root);
    for(int ix = 0; ix < matrix.size(); ++ix) {
        for(int jx = 0; jx < matrix[ix].size(); ++jx) {
            std::cout << matrix[ix][jx] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
