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
        return false;
    }
};

int main() {
    return 0;
}