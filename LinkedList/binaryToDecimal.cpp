class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimal = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            decimal = (decimal << 1) | temp->val;
            temp = temp->next;
        }
        return decimal;
    }
};