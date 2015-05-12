#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *p = head, *new_head = p->next, *q = p->next;
        ListNode *prev = NULL, *r = NULL;
        while(p != NULL && q != NULL) {
            r = q->next;

            p->next = q->next;
            q->next = p;

            if(prev != NULL) {
                prev->next = q;
            }

            prev = p;
            p = r;
            q = (p ? p->next : NULL);
        }

        return new_head;
    }
};

int main() {
    Solution s;
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    ListNode *q = new ListNode(3);
    q->next = new ListNode(4);
    p->next->next = q;

    ListNode *r = s.swapPairs(p);
    while(r != NULL) {
        std::cout << r->val << " ";
        r = r->next;
    }
    std::cout << std::endl;

    return 0;
}
