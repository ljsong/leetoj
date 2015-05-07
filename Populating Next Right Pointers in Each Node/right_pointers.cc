#include <iostream>
#include <deque>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) {
            return ;
        }

        deque<TreeLinkNode *> que;
        que.push_back(root);
        int count_of_leafs = 1, level_count = 0;
        TreeLinkNode *p = NULL, *prev = NULL;

        while(!que.empty()) {
            p = que.front();
            que.pop_front();
            ++level_count;

            if(prev) {
                prev->next = p;
            }
            prev = p;

            if(level_count == count_of_leafs) {
                level_count = 0;
                count_of_leafs <<= 1;
                p->next = NULL;
                prev = NULL;
            }

            if(p->left != NULL) {
                que.push_back(p->left);
            }

            if(p->right != NULL) {
                que.push_back(p->right);
            }
        }
    }
};

int main() {
    Solution s;
    TreeLinkNode *root = new TreeLinkNode(1);
    TreeLinkNode *left = new TreeLinkNode(2);
    TreeLinkNode *right = new TreeLinkNode(3);

    //left->left = new TreeLinkNode(4);
    //left->right = new TreeLinkNode(5);
    //right->left = new TreeLinkNode(6);
    //right->right = new TreeLinkNode(7);

    root->left = left;
    root->right = right;
    s.connect(root);

    TreeLinkNode *p = root;
    while(p != NULL) {
        TreeLinkNode *q = p;
        while(q != NULL) {
            std::cout << q->val << " ";
            q = q->next;
        }
        p = p->left;
    }
    std::cout << std::endl;

    return 0;
}
