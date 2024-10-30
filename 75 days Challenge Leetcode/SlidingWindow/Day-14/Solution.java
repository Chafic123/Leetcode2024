class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;

        // Calculate the sum of the first 'k' elements to form the initial window
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        // Set maxSum to the sum of the initial window
        double maxSum = windowSum;

        // Slide the window across the array
        for (int i = k; i < n; i++) {
            // Add the next element and remove the element that is now outside the window
            windowSum += nums[i] - nums[i - k];
            // Update maxSum if the current window sum is greater
            maxSum = Math.max(maxSum, windowSum);
        }

        // Return the maximum average by dividing the maxSum by 'k'
        return maxSum / k;
    }
}
