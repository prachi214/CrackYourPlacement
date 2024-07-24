// Remove Linked List Elements

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // Dummy node to handle the case where the head node needs to be deleted
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr != NULL)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
                delete curr;       // Delete the target node
                curr = prev->next; // Update curr
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};