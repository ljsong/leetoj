#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}

class Solution {
public:
    voide deleteNode(ListNode *node) {
        if (NULL == node) {
            return ;
        } else if(node->next == NULL) {
            node = NULL;
            return ;
        }

        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
    }
};

int main() {
    Solution s;

    return 0;
}
