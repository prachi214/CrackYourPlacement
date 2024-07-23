class Solution
{
public:
   ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
   {
      ListNode *t1 = l1;
      ListNode *t2 = l2;
      // create dummy node
      ListNode *dummyNode = new ListNode(-1);
      //  for traversing LL
      ListNode *curr = dummyNode;
      int carry = 0, sum = 0;
      while (t1 != NULL || t2 != NULL || carry)
      {
         sum = carry;
         if (t1 != NULL)
         {
            sum += t1->val;
         }
         if (t2 != NULL)
         {
            sum += t2->val;
         }
         ListNode *newNode = new ListNode(sum % 10);
         carry = sum / 10;
         curr->next = newNode;
         curr = curr->next;
         if (t1)
         {
            t1 = t1->next;
         }
         if (t2)
         {
            t2 = t2->next;
         }
      }
      return dummyNode->next;
   }
};