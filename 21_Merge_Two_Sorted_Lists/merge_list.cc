#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        ListNode *first = list1, *second = list2;
        ListNode *head = nullptr, *tail = nullptr;
        while(first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                add_node(head, tail, first);
                first = first->next;
            } else {
                add_node(head, tail, second);
                second = second->next;
            }
        }

        while(first != nullptr) {
            add_node(head, tail, first);
            first = first->next;
        }

        while(second != nullptr) {
            add_node(head, tail, second);
            second = second->next;
        }

        return head;
    }

private:
    void add_node(ListNode *&head, ListNode *&tail, ListNode *node) {
        if(head == nullptr) {
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
