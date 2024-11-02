class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)  // Edge case: if list is empty or has only one node
            return nullptr;         // Return null since there's no middle node to delete

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;    // Pointer to track node before slow
        
        // Move fast by 2 steps and slow by 1 step until fast reaches end of list
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;             // Move prev to current slow node
            slow = slow->next;       // Move slow to the next node
            fast = fast->next->next; // Move fast two nodes ahead
        }
        
        prev->next = slow->next;     // Skip the middle node
        return head;                 // Return the head of the modified list
    }
};
