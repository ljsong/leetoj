/* Given a binary search tree, write a function kthSmallest 
 * to find the kth smallest element in it.
 *
 * Note: You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you 
 * need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

    }
};

int main() {
    Solution s;

    return 0;
}
