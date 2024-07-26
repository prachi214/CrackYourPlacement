class Solution {
public:

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.empty())
            return NULL;

        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            // merge 2, 2 lists at a time
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};