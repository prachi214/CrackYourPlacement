// Reverse Nodes in k-Group

class Solution {
public:

int findLength(ListNode* &head) {
  ListNode* temp = head;
  int len = 0;
  while(temp != NULL) {
    len++;
    temp = temp->next;
  }
  return len;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if(head == NULL) return head;
        // SINGLE NODE
        if(head->next == NULL) return head;
        // reverse 1st k node
      ListNode* prev = NULL;
           ListNode* curr = head;
        ListNode* nextNode = curr->next;
        int pos = 0;
        int len = findLength(head);
        // check kth node present or not
        if(len<k) return head;
        while(pos<k){
            nextNode = curr->next;
                    curr->next = prev;
        prev = curr;
        curr = nextNode;
        pos++;
        }

ListNode* recursionAns = NULL;
if(nextNode != NULL){
    recursionAns = reverseKGroup(nextNode, k);
    head->next = recursionAns;
}
return prev;
    }
};