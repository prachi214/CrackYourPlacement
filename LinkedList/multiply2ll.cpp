class solution {
  public:
    long long multiplyTwoLists(Node *l1, Node *l2) {
        long long num1 = 0, num2 = 0;
long long MOD =  1000000007;
    // make number  from first linked list 
    while (l1 != NULL) {
        num1 = (num1 * 10 + l1->data) % MOD;
        l1 = l1->next;
    }
        // make number  from second linked list 
    while (l2 != NULL) {
        num2 = (num2 * 10 + l2->data) % MOD;
        l2 = l2->next;
    }
    // Return the multiplication of both nums
    return (num1 * num2) % MOD;
    }
};