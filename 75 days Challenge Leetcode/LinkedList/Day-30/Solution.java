class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}

class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) // Edge case: empty or single-node list
            return head;

        ListNode odd = head;               // Odd list starts with head
        ListNode even = head.next;         // Even list starts with second node
        ListNode evenHead = even;          // Remember the start of the even list

        while (even != null && even.next != null) {
            odd.next = even.next;          // Link current odd node to the next odd
            odd = odd.next;                // Move to the next odd node
            
            even.next = odd.next;          // Link current even node to the next even
            even = even.next;              // Move to the next even node
        }

        odd.next = evenHead;               // Append even list at the end of odd list
        return head;                       // Return the modified list
    }
}
