/* Given a binary search tree, write a function kthSmallest 
 * to find the kth smallest element in it.
 *
 * Note: You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you 
 * need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */

#include <iostream>
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return 0;
        }

        std::list<TreeNode *> stak;
        TreeNode *p = root;
        int cnt = 0;
        stak.push_back(root);

        while(!stak.empty()) {
            while(p && p->left) {
                stak.push_back(p->left);
                p = p->left;
            }    

            TreeNode *q = stak.back();
            stak.pop_back();
            if (++cnt == k) {
                return q->val;
            }

            p = q->right;
            if (p != NULL) {
                stak.push_back(p);
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(20);
    TreeNode *left = new TreeNode(15);
    TreeNode *right = new TreeNode(25);
    left->left = new TreeNode(7);
    left->right = new TreeNode(16);
    right->left = new TreeNode(23);
    right->left->right = new TreeNode(24);
    right->right = new TreeNode(27);
    right->right->left = new TreeNode(26);

    root->left = left;
    root->right = right;

    std::cout << s.kthSmallest(root, 7) << std::endl;

    return 0;
}
