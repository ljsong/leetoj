#include <iostream>

/**
 * 给你一个单链表的头节点 head ，请你判断该链表是否为 回文链表。如果是，返回 true ；否则，返回 false 。
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        int length = 0, ix = 1;
        ListNode *p = head, *q = nullptr;
        while(p != nullptr) {
            ++length;
            p = p->next;
        }

        p = head;
        while(p != nullptr && ix < (length + 1) / 2) {
            ++ix;
            p = p->next;
        }

        q = p->next;
        p->next = nullptr;
        q = reverse(q);

        ListNode* first = head, *second = q;
        while(second != nullptr) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }

private:
    ListNode* reverse(ListNode*& head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* p = head, *q = nullptr, *r = nullptr;
        p = head;
        while(p != nullptr) {
            r = p->next;
            if (q == nullptr) {
                q = p;
                q->next = nullptr;
            } else {
                p->next = q;
                q = p;
            }
            p = r;
        }

        return q;
    }
};

int main() {
    ListNode *root = new ListNode(3, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(2, new ListNode(1))))));
    Solution s;
    std::cout << s.isPalindrome(root) << std::endl;
}