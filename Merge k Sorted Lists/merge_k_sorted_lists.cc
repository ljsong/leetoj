/**
 * Definition for singly-linked list.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *root = nullptr;
        ListNode *tail = nullptr;
        auto cmp = [](ListNode* left, ListNode* right) { return left->val > right->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> prique(cmp);

        for(size_t ix = 0; ix < lists.size(); ++ix) {
            if (lists[ix] != nullptr) {
                prique.push(lists[ix]);
            }
        }

        while(!prique.empty()) {
            ListNode *p = prique.top();
            prique.pop();

            ListNode *q = p->next;
            if (q != nullptr) {
                prique.push(q);
            }

            if (root == nullptr) {
                root = p;
                tail = p;
            } else {
                tail->next = p;
                tail = p;
            }
        }

        return root;
    }
};

int main() {
    Solution s;
    ListNode *p = new ListNode(5);
    ListNode *r = new ListNode(9);
    ListNode *q = new ListNode(2);
    vector<ListNode*> vec;

    vec.push_back(p);
    vec.push_back(r);
    vec.push_back(q);

    ListNode *newNode = s.mergeKLists(vec);
    while(newNode != nullptr) {
        std::cout << newNode->val << " ";
        newNode = newNode->next;
    }
    std::cout << std::endl;
}
