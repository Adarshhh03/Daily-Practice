class Solution {
public:
    ListNode* mergeSortedList(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (left && right) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left) temp->next = left;
        else temp->next = right;

        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = right ? sortList(right) : nullptr;

        return mergeSortedList(leftSorted, rightSorted);
    }
};
