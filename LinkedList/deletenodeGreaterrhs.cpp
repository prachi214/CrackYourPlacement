class Solution
{
    public:
    Node *compute(Node *head)
    {
        Node* temp = head;
        // base case
             if (temp->next == NULL) {
            return temp;
        }
        // recursive call
        Node* connect = compute(temp->next);
// get right greater ele
        if (temp->data >= connect->data) {
            temp->next = connect;
            return temp;
        }
        return connect;
    }  
};