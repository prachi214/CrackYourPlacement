//Remove Duplicates from Sorted List

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        // only unique elements
        while(temp!= NULL && temp->next !=NULL){
            ListNode* nextNode = temp->next;
            // only for duplicate elements
            while(nextNode !=NULL && nextNode->val == temp->val){
                ListNode* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }
            temp->next = nextNode;
            temp = temp->next;
        }
        return head;
    }
};