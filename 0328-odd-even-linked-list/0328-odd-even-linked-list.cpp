class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* oddHead = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* oddTail = nullptr;
        ListNode* evenTail = nullptr;

        ListNode* curr = head;
        int pos = 1;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = nullptr;  

            if (pos % 2 == 1) {
                if (!oddHead) {
                    oddHead = oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = curr;
                }
            } else {
                if (!evenHead) {
                    evenHead = evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = curr;
                }
            }

            curr = nextNode;
            pos++;
        }

       
        oddTail->next = evenHead;

        return oddHead;
    }
};
