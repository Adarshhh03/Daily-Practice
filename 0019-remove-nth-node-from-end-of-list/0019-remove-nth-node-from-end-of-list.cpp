class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead to maintain a gap of n
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both fast and slow together until fast reaches end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next;
    }
};
