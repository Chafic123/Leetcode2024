class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next:  # Edge case: empty or single-node list
            return head

        odd = head                    # Start of odd list
        even = head.next              # Start of even list
        even_head = even              # Store the start of even list

        while even and even.next:
            odd.next = even.next      # Link current odd node to the next odd
            odd = odd.next            # Move to the next odd node
            
            even.next = odd.next      # Link current even node to the next even
            even = even.next          # Move to the next even node

        odd.next = even_head          # Append even list at the end of odd list
        return head                   # Return the modified list
