/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
     node->val = node->next->val;        // Copy the value from the next node
     ListNode* temp = node->next;        // Store the next node
     node->next = node->next->next;      // Skip the next node
     delete temp;                        // Optional: free the memory of the skipped node
    }
};