#include <iostream>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int length = 0;
        ListNode* p = head;
        while(p != nullptr) {
            ++length;
            p = p->next;
        }

        int mid = length >> 1;
        int ix = 0;
        p = head;
        while(ix < mid) {
            p = p->next;
            ++ix;
        }

        return p;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
//    head->next->next->next = new ListNode(4);
    
    ListNode *p = s.middleNode(head);
    std::cout << p->val << std::endl;


    return 0;
}

