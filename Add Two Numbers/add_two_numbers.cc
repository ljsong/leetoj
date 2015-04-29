#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p = l1, *q = l2;
        ListNode *result = NULL, *tail = result;
        int carry = 0, sum = 0;

        while(p != NULL && q != NULL) {
            sum = (p->val + q->val + carry);
            carry = sum / 10;
            sum %= 10;

            ListNode *tmp = new ListNode(sum);
            if(result == NULL) {
                result = tmp;
            } else {
                tail->next = tmp;
            }
            tail = tmp;

            p = p->next;
            q = q->next;
        }

        while(p != NULL) {
            sum = p->val + carry;
            carry = sum / 10;
            sum %= 10;

            tail = tail->next = new ListNode(sum);
            p = p->next;
        }

        while(q != NULL) {
            sum = q->val + carry;
            carry = sum / 10;
            sum %= 10;

            tail = tail->next = new ListNode(sum);
            q = q->next;
        }

        if(carry != 0) {
            tail = tail->next = new ListNode(carry);

        }

        return result;
    }
};

int main() {
    Solution s;
    ListNode *p = new ListNode(1);
    ListNode *q = new ListNode(9);
    ListNode *tmp = new ListNode(9);
    q->next = tmp;

    ListNode *result = s.addTwoNumbers(p, q);
    for(; result; result = result->next) {
        std::cout << result->val;
    }

    std::cout << std::endl;

    delete p;
    delete tmp;
    delete q;

    return 0;
}
