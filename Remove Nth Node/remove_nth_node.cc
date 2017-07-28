#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0) {
            return NULL;
        }

        ListNode *p = head;
        vector<ListNode *> pVector;

        while(p != NULL) {
            pVector.push_back(p);
            p = p->next;
        }

        int len = pVector.size();
        if (len == 1) {
            return NULL;
        } else if (len == n) {
            head = head->next;
        } else {
            ListNode* prev = pVector[len - n - 1];
            prev->next = prev->next->next;
        }

        return head;
    }
};

int main() {
    Solution s;

    return 0;
}
