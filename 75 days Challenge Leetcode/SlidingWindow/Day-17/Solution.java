class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        // Return 0 if the input array is empty
        if (n == 0) return 0;

        int start = 0, end;           // Initialize start and end pointers for the sliding window
        int num_zeroes = 0;           // Count of zeroes in the current window
        int max_length = 0;           // Maximum length of the subarray found

        // Iterate with the end pointer to expand the window
        for (end = 0; end < n; end++) {
            // Count the number of zeroes encountered
            if (nums[end] == 0) num_zeroes++;

            // If there are more than one zero, shrink the window from the start
            while (num_zeroes > 1) {
                // If the start element is a zero, decrease the count of zeroes
                if (nums[start] == 0) num_zeroes--;
                start++;  // Move the start pointer to the right
            }

            // Update the maximum length of the subarray (excluding at most one zero)
            max_length = Math.max(max_length, end - start);
        }

        return max_length; // Return the maximum length found
    }
}
