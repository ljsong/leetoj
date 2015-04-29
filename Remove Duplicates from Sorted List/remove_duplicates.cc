#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * deleteDuplicates(ListNode *head) {
        ListNode *p = head;
        ListNode *n = (p == NULL ? NULL : p->next);

        while(p != NULL) {
            if(n == NULL) {
                break;
            }

            if(p->val == n->val) {
                p->next = n->next;
                n = n->next;
            } else {
                p = n;
                n = n->next;
            }
        }

        return head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(1);

    ListNode *q = s.deleteDuplicates(head);
    while(q != NULL) {
        std::cout << q->val << " ";
        q = q->next;
    }
    std::cout << std::endl;

    return 0;

    return 0;
}
