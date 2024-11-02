class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Find the middle of the list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        // Step 3: Calculate the twin sum
        int max_sum = 0;
        ListNode* first_half = head;
        ListNode* second_half = prev;
        while (second_half) {
            max_sum = max(max_sum, first_half->val + second_half->val);
            first_half = first_half->next;
            second_half = second_half->next;
        }

        return max_sum;
    }
};
