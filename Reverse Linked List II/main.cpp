#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int cnt = 1;
        ListNode *start = getNode(head, m);
        ListNode *end = getNode(head, n);
        ListNode *remain = end->next;

        if (m == 1) {
            end->next = nullptr;
            start = reverse(start);
            start->next = remain;
            return start;
        } else {
            end->next = nullptr;
            ListNode *p = head;
            for(; p->next != start; p = p->next) {}
            p->next = reverse(start);
            start->next = remain;
            return head;
        }
    }

private:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* p = head, *q = nullptr, *r = p;
        while(p != nullptr) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        return q;
    }

    ListNode* getNode(ListNode* head, int index) {
        ListNode *p = head;

        for (int ix = 1; ix < index && p != nullptr; p = p->next, ++ix) {}

        return p;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
