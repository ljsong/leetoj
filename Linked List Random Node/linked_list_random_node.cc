#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head the linked list's head.
     * Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        root = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *p = root;
        int num = root->val;
        int idx = 1;

        while(p != NULL) {
            if (rand() % idx++ == 0) {
               num = p->val;
            }
            p = p->next;
        } 
        
        return num;
    }

private:
    ListNode* root;
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution* obj = new Solution(head);
    for(int ix = 0; ix < 9; ++ix) {
        std::cout << obj->getRandom() << " ";
    }
    std::cout << std::endl;

    return 0;
}
