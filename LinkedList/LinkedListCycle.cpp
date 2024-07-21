class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL) {
            fast = fast->next;
            if(fast!=NULL) {
     fast = fast->next;
    //  now move slow
    slow = slow->next;
            }
if(slow == fast) return true;
        }
        //loop not present
        return false;
    }
};