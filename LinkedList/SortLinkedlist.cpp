class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        // middle ,1st middle
        while (fast->next != NULL)
        {
            // increment fast one by one , if fast->next = null h then again next krne pr error that's by
            fast = fast->next;
            if (fast->next != NULL)
            {
                fast = fast->next;
                // now fast ne 2 step chal liye h
                // ab slow ko bhi  ek step
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode *mergeTwoList(ListNode *list1, ListNode *list2)
    {
        if (list1 == 0)
            return list2;
        if (list2 == 0)
            return list1;

        ListNode *ans = new ListNode(-1);
        ListNode *mptr = ans;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                mptr->next = list1;
                mptr = list1;
                list1 = list1->next;
            }
            else
            {
                mptr->next = list2;
                mptr = list2;
                list2 = list2->next;
            }
        }
        if (list1)
            mptr->next = list1;
        if (list2)
            mptr->next = list2;

        return ans->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
// find mid
        ListNode *middle = middleNode(head);
        // break list
        ListNode *right = middle->next;
        middle->next = NULL;
        ListNode *left = head;

//recursive call
        left = sortList(left);
        right = sortList(right);
        // return sorted list
        return mergeTwoList(left, right);
    }
};