class Solution
{
public:
    // step1, avoid hash DS

    void insertCopyNodeInBetween(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            //    Node* nextElement = temp->next;
            Node *copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = temp->next->next;
        }
    }

    // step 2
    void connectRandomPointers(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *copyNode = temp->next;

            if (temp->random)
            {
                copyNode->random = temp->random->next;
            }

            else
            {
                copyNode->random = NULL;
            }

            temp = temp->next->next;
        }
    }

    // step 3
    Node *extractCopyList(Node *head)
    {
        Node *temp = head;
        Node *dummyNode = new Node(-1);
        Node *res = dummyNode;

        while (temp != NULL)
        {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
    Node *copyRandomList(Node *head)
    {

        insertCopyNodeInBetween(head);
        connectRandomPointers(head);
        return extractCopyList(head);
    }
};