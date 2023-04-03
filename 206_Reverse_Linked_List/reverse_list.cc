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
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *new_head = nullptr;
        ListNode *p = head, *prev = nullptr;

        while(p != nullptr) {
            prev = new_head;
            new_head = p;
            p = p->next;
            new_head->next = prev;
        }

        return new_head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode *p = s.reverseList(head);
    while(p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;

    return 0;
}
