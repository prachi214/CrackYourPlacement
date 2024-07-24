//odd even LL
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save the head of the even list
        
        while (even != NULL && even->next != NULL) {
            odd->next = even->next; // Link odd nodes
            odd = odd->next;
            even->next = odd->next; // Link even nodes
            even = even->next;
        }
        
        odd->next = evenHead; // Connect odd nodes with even head
        
        return head;
    }
};
