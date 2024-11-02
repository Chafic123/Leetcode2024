#include <stack>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;  // Edge case: if the list is empty
        stack<ListNode*> stack;     // Stack to hold nodes
        ListNode* current = head;  
        
        // Push all nodes onto the stack
        while (current) {
            stack.push(current);
            current = current->next;
        }
        
        // The new head is the last element from the original list
        ListNode* newHead = stack.top();
        stack.pop();
        current = newHead;
        
        // Rebuild the reversed list
        while (!stack.empty()) {
            current->next = stack.top();
            stack.pop();
            current = current->next;
        }
        
        current->next = nullptr; // Set the end of the new list to nullptr
        return newHead;          // Return the new head
    }
};
