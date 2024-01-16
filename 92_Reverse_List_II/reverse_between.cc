#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }

        int ix = 1;
        ListNode* p = head, *q = nullptr;
        ListNode* prev = nullptr, *tail = nullptr, *sub_root = nullptr;

        // find the prev
        while(ix <= left - 1) {
            prev = p;
            p = p->next;
            ++ix;
        }

        tail = p;
        while(p != nullptr && ix <= right) {
            q = p->next;
            if (sub_root == nullptr) {
                sub_root = p;
                sub_root->next = nullptr;
            } else {
                p->next = sub_root;
                sub_root = p;
            }

            p = q;
            ++ix;
        }
        
        tail->next = q;
        if (prev == nullptr) {
            return sub_root;
        } 

        prev->next = sub_root;
        return head;
    }
};

int main() {
    Solution s;
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);

    root = s.reverseBetween(root, 1, 5);

    ListNode*p = root;
    while(p != nullptr) {
        std::cout << p->val << " ";
        p = p->next;
    }

    std::cout << std::endl;
    return 0;
}
