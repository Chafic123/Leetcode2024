class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:  # Edge case: if the list is empty
            return None

        stack = []    # Stack to hold nodes
        current = head
        
        # Push all nodes onto the stack
        while current:
            stack.append(current)
            current = current.next

        # The new head is the last element from the original list
        new_head = stack.pop()
        current = new_head
        
        # Rebuild the reversed list
        while stack:
            current.next = stack.pop()
            current = current.next
        
        current.next = None  # Set the end of the new list to None
        return new_head      # Return the new head
