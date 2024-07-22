// Reverse Nodes in k-Group

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // base case
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;

        // reverse 1st k node
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = curr->next;

        int pos = 0;
        while (pos < k)
        {
            pos++;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }

        ListNode *recursionAns = NULL;
        if (nextNode != NULL)
        {
            recursionAns = reverseKGroup(nextNode, k);
            head->next = recursionAns;
        }
        return prev;
    }
};