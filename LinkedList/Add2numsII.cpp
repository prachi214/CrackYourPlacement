//  Add Two Numbers II

class Solution
{
public:
    ListNode *reverseUsingRecursion(ListNode *prev, ListNode *currSuml)
    {

        // base case
        if (currSuml == NULL)
        {
            return prev;
        }
        // 1 case hum solve krenge
        ListNode *nextNode = currSuml->next;
        currSuml->next = prev;
        prev = currSuml;
        currSuml = nextNode;

        // baaaki  - recursion karega
        return reverseUsingRecursion(prev, currSuml);
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *prev1 = NULL;
        ListNode *curr1 = l1;
        ListNode *prev2 = NULL;
        ListNode *curr2 = l2;

        // return head
        ListNode *t1 = reverseUsingRecursion(prev1, curr1);
        ListNode *t2 = reverseUsingRecursion(prev2, curr2);
        // create dummy node
        ListNode *dummyNode = new ListNode(-1);
        //  for traversing LL
        ListNode *currSuml = dummyNode;
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
            currSuml->next = newNode;
            currSuml = currSuml->next;
            if (t1)
            {
                t1 = t1->next;
            }
            if (t2)
            {
                t2 = t2->next;
            }
        }

        return reverseUsingRecursion(NULL, dummyNode->next);
    }
};