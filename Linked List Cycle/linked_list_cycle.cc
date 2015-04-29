class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = NULL, *fast = NULL;
        bool has_cycle = false;
        
        slow = fast = head;
        while(slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if(fast) {
                fast = fast->next;
            }
            
            if(slow && slow == fast) {
                has_cycle = true;
                break;
            }
        }
        
        return has_cycle;
    }
};
