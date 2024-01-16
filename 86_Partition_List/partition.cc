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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* p = head, *prev = nullptr;
        while(p != nullptr) {
            if (p->val >= x) {
                break;
            }
            prev = p;
            p = p->next;
        }

        ListNode* q = p == nullptr ? nullptr : p->next, *r = p;
        while(q != nullptr) {
            if (q->val < x) {
                r->next = q->next;
                if (prev == nullptr) {
                    prev = q;
					head = prev;
                } else {
                    prev->next = q;
                    prev = q;
                }
            } else {
	            r = q;           	
            }
	        q = q->next; 
        }

        if (prev != nullptr) {
            prev->next = p;
        }

        return head;
    }
};

int main() {
    Solution s;
    ListNode* root = new ListNode(1);
    root->next = new ListNode(1);
    // root->next->next = new ListNode(3);
    // root->next->next->next = new ListNode(2);
    // root->next->next->next->next = new ListNode(5);
	// root->next->next->next->next->next = new ListNode(2);

    root = s.partition(root, 2);
    ListNode* p = root;
    while(p != nullptr) {
        std::cout << p->val << " ";
        p = p->next;
    }

    std::cout << std::endl;
    return 0;
}
