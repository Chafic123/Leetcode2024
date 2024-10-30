class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right;

        // Iterate with the right pointer
        for (right = 0; right < n; right++) {
            // Decrease k if we encounter a 0, as it would need flipping to become 1
            if (nums[right] == 0) k--;
            
            // If k goes below 0, we have exceeded the number of allowed flips
            if (k < 0) {
                // Increment k if the left pointer is at a 0, restoring one flip allowance
                if (nums[left] == 0) k++;
                // Move the left pointer to shrink the window
                left++;
            }
        }

        // The length of the longest valid subarray is the window size
        return right - left;
    }
};
