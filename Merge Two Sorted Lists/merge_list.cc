#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p = l1, *q = l2, *head = NULL, *tail = NULL;

        while(p != NULL && q != NULL) {
            if(p->val < q->val) {
                addNode(head, tail, p);
                p = p->next;
            } else {
                addNode(head, tail, q);
                q = q->next;
            }
        }

        while(p != NULL) {
            addNode(head, tail, p);
            p = p->next;
        }

        while(q != NULL) {
            addNode(head, tail, q);
            q = q->next;
        }

        return head;
    }

private:
    void addNode(ListNode *&head, ListNode *&tail, ListNode *node) {
        if(head == NULL) {
            head = node;
            tail = head;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);

    //ListNode *head1 = NULL;
    ListNode *head1 = new ListNode(2);
    //head1->next = new ListNode(4);

    ListNode *root = s.mergeTwoLists(head, head1);
    ListNode *p = root;

    while(p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }

    std::cout << std::endl;

    return 0;
}
