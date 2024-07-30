class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; 
        ListNode* curr = head;  
        while (curr != NULL) {
            bool hasDuplicates = false;
            while (curr->next != NULL && curr->val == curr->next->val) {
                hasDuplicates = true;
                ListNode* duplicate = curr->next;
                curr->next = duplicate->next;
                delete duplicate; 
            }
            
            if (hasDuplicates) {
                ListNode* duplicate = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete duplicate; 
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};