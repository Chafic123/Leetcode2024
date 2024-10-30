class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Initialize the sum of the first 'k' elements
        double windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        // Set maxSum initially as the sum of the first window
        double maxSum = windowSum;

        // Slide the window, add next element, subtract the first element in the previous window
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);  // Update maxSum if current windowSum is higher
        }

        // Return the maximum average by dividing maxSum by 'k'
        return maxSum / k;
    }
};
