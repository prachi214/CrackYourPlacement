class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastptr = head;
    ListNode* slowp = head;

    // Move the fastptr pointer N nodes ahead
    for (int i = 0; i < n; i++)
        fastptr = fastptr->next;

    // If fastptr becomes NULL,
    // the Nth node from the end is the head
    if (fastptr == NULL)
        return head->next;

    // Move both pointers until fastptr reaches the end
    while (fastptr->next != NULL) {
        fastptr = fastptr->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    ListNode* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
    }
};