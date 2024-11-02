class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}

class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if (head == null || head.next == null) // If list is empty or has one node
            return null; // Return null, as there is no middle to delete

        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;

        // Move fast pointer two steps and slow pointer one step
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = slow.next; // Skip the middle node
        return head;           // Return the modified list
    }
}
