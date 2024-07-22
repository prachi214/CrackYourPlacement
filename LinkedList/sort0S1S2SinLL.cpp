// Sort a linked list of 0s, 1s and 2s

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        if (!head || !head->next)
            return head;
        //  create dummy nodes

        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);

        // like 3 seperate LL
        Node *zero = zeroHead;
        Node *one = oneHead;
        Node *two = twoHead;
        Node *temp = head;

        while (temp)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            // (temp->data == 2)
            else
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        // connect LL0, LL1, LL2

        zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
        one->next = (twoHead->next);
        two->next = NULL;

        Node *newHead = zeroHead->next;

        // deallocate the dummy nodes.
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};