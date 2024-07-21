class Solution{
public:

ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
    
        //base case
        if(curr == NULL) {
            return prev;
        }
        //1 case hum solve krenge
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        //baaaki  - recursion karega
        return reverseUsingRecursion(prev, curr);
    }

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;

    // return head
return reverseUsingRecursion(prev,curr);
    }

};