//Middle of the Linked List

class Solution {
public:

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL) {
            // increment fast one by one , if fast->next = null h then again next krne pr error that's by
            fast = fast ->next;
            if(fast != NULL) {
                fast = fast -> next;
                //now we can say fast can take 2 steps 
                //ab slow ko bhi chal skta h ek step
                slow = slow -> next;
            }
        }
        return slow;
    }
};