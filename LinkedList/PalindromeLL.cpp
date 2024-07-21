// Palindrome Linked List 

class Solution {
public:

ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL) {
            fast = fast ->next;
            if(fast->next != NULL) {
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        return slow;
    }

        ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        //base case
        if(curr == NULL) {
            // now head
            return prev;
        }
        //1 case hum solve krenge
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        //baaaki  - recursion karega
        return reverseUsingRecursion(prev, curr);
    }
    bool compareList(ListNode* head1, ListNode* head2) {
            ListNode* temp1 = head1;
                ListNode* temp2 = head2;
        while( temp2 != NULL) {
            if(temp1 -> val != temp2->val) {
                return false;
            }
            else {
                temp1 = temp1->next;
                temp2= temp2->next;
            }
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        //break into 2 havles
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode -> next;
        midNode->next = NULL;
        //reverse second half

        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr);
        //compare both linked list
        bool ans = compareList(head, head2);
        return ans;
    }
    };