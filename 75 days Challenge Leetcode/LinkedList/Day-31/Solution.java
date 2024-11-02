import java.util.Stack;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) return null;  // Edge case: if the list is empty
        Stack<ListNode> stack = new Stack<>(); // Stack to hold nodes
        ListNode current = head;
        
        // Push all nodes onto the stack
        while (current != null) {
            stack.push(current);
            current = current.next;
        }
        
        // The new head is the last element from the original list
        ListNode newHead = stack.pop();
        current = newHead;
        
        // Rebuild the reversed list
        while (!stack.isEmpty()) {
            current.next = stack.pop();
            current = current.next;
        }
        
        current.next = null; // Set the end of the new list to null
        return newHead;      // Return the new head
    }
}
