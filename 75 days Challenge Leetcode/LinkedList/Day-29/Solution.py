class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteMiddle(self, head: ListNode) -> ListNode:
        if not head or not head.next:  # If list is empty or has one node
            return None                # Return None, no middle to delete

        slow = head
        fast = head
        prev = None

        # Move fast by 2 steps and slow by 1 step until fast reaches the end
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        prev.next = slow.next  # Skip the middle node
        return head            # Return the modified list
