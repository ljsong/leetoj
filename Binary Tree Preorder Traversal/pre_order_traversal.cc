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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ivec;
        vector<TreeNode *> stak;

        if(root == NULL) {
            return ivec;
        }

        stak.push_back(root);
        while(!stak.empty()) {
            TreeNode *node = stak.back();
            stak.pop_back();
            ivec.push_back(node->val);
            
            if(node->right != NULL) {
                stak.push_back(node->right);
            }
            if(node->left != NULL) {
                stak.push_back(node->left);
            }
        }

        return ivec;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(5);
    TreeNode *left = new TreeNode(9);
    TreeNode *right = new TreeNode(7);

    root->left = left;
    root->right = right;

    vector<int> ivec = s.preorderTraversal(root);
    for(vector<int>::iterator itr = ivec.begin(); itr != ivec.end(); ++itr) {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    return 0;
}
