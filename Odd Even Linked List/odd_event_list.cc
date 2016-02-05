/* Given a singly linked list, group all odd nodes together followed by the even nodes. 
 * Please note here we are talking about the node number and not the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 *
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input. 
 * The first node is considered odd, the second node even and so on ...
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* OddEventList(ListNode* head) {
        int counter = 1;

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *p = head, *q = head->next, *r = q->next;
        ListNode *tail = q;
        p->next = NULL;
        q->next = NULL;

        while (r != NULL) {
            if (counter & 1) {
                p->next = r;
                p = r;
            } else {
                tail->next = r;
                tail = r; 
            }
            ++counter;
            r = r->next;
        }

        p->next = q;
        tail->next = NULL;

        return head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode *p = head;
    head = s.OddEventList(head);
    while (p != NULL) {
        std::cout << p->val << ", ";
        p = p->next;
    }
    std::cout << std::endl;

    return 0;
}
