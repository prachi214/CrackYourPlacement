// Intersection of Two Linked Lists

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(headA == NULL|| headB == NULL) return NULL;
       ListNode *temp1 = headA;
           ListNode *temp2 = headB;
           while(temp1 != temp2){
            // move temp1 and temp2 1 -1 steps simultaneously
            temp1 = temp1 ->next;
            temp2 = temp2->next;
            // intersection node
            if(temp1 == temp2) return temp1;
            // when temp1 or temp2 on null
            if(temp1 == NULL) temp1 = headB;
               if(temp2 == NULL) temp2 = headA;
           }
        //    no intersection point exist
              return temp1;
    } 
};