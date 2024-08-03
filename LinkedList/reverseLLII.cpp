class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode *dummyNode = new ListNode(-1); 
          ListNode *temp = head;
             ListNode *currNode = temp;
   ListNode *preNode = NULL;
       dummyNode->next = temp;
       ListNode *leftNode = dummyNode;

      for(int i = 0;i<left-1;i++)  {
leftNode = leftNode->next;
currNode = currNode->next;
      }  
ListNode* subListHead = currNode;

for(int i =0; i<=(right- left); i++){
    ListNode *nextNode = currNode->next;
    currNode->next = preNode;
    preNode = currNode;
    currNode = nextNode;
}
leftNode->next = preNode;
subListHead->next = currNode;

return dummyNode->next;

    }
};