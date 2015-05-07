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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ivec;

        if(root == NULL) {
            return ivec;
        }
            
        vector<TreeNode *> stak;
        TreeNode *p = root->left;
        stak.push_back(root);

        while(!stak.empty()) {
            while(p != NULL) {
                stak.push_back(p);
                p = p->left;
            }
            TreeNode *q = stak.back();
            stak.pop_back();
            ivec.push_back(q->val);

            if(q->right) {
                stak.push_back(q->right);
                p = q->right->left;
            }
        };

        return ivec;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);

    left->left = new TreeNode(4);
    left->right = new TreeNode(5);
    right->left = new TreeNode(6);
    right->right = new TreeNode(7);

    root->left = left;
    root->right = right;

    vector<int> ivec = s.inorderTraversal(root);
    for(int ix = 0; ix < ivec.size(); ++ix) {
        std::cout << ivec[ix] << " ";
    }
    std::cout << std::endl;

    return 0;
}
    
