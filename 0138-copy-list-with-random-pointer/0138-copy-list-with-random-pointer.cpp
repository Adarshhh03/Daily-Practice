class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step 1: Clone each node and insert it after original
        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // Step 2: Set random pointers for copied nodes
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // Step 3: Separate original and cloned lists
        temp = head;
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;

        while (temp) {
            copyCurr->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            copyCurr = copyCurr->next;
        }

        return dummy->next;
    }
};
