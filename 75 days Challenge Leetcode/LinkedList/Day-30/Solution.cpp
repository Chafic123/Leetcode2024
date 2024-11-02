class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // Edge case: empty or single-node list

        ListNode* odd = head;           // Start of odd nodes
        ListNode* even = head->next;    // Start of even nodes
        ListNode* evenHead = even;      // Store the head of the even list

        while (even && even->next) {
            odd->next = even->next;     // Link current odd to the next odd
            odd = odd->next;            // Move to the next odd node
            
            even->next = odd->next;     // Link current even to the next even
            even = even->next;          // Move to the next even node
        }
        
        odd->next = evenHead;           // Append the even list at the end of odd list
        return head;                    // Return the modified head
    }
};
