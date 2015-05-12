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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ivec;

        if(root == NULL) {
            return ivec;
        }

        vector<TreeNode *> stak;
        vector<bool> fvec;
        stak.push_back(root);
        fvec.push_back(false);
        TreeNode *p = root->left;

        while(!stak.empty()) {
            while(p != NULL) {
                stak.push_back(p);
                p = p->left;
                fvec.push_back(false);    //firstly, the visit flag is set to false
            }

            bool visit = fvec.back();
            TreeNode *q = stak.back();
            if(visit == false) {
                fvec.pop_back();
                fvec.push_back(true);
                if(q->right) {
                    stak.push_back(q->right);
                    fvec.push_back(false);
                    p = q->right->left;
                }
            } else {
                fvec.pop_back();
                ivec.push_back(q->val);
                stak.pop_back();
            }
        }

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

    vector<int> ivec = s.postorderTraversal(root);
    for(int ix = 0; ix < ivec.size(); ++ix) {
        std::cout << ivec[ix] << " ";
    }
    std::cout << std::endl;

    return 0;
}
