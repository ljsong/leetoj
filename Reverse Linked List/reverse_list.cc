#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if(head == NULL) {
            return head;
        }
        
        ListNode *p = head, *q = p->next, *r = NULL;
        p->next = NULL;

        while(q != NULL) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }

        return p;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    //head->next->next = new ListNode(3);

    ListNode *p = s.reverseList(head);
    while(p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;

    return 0;
}
