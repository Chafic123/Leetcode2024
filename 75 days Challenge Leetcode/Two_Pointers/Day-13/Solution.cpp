class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array to use two-pointer technique
        int left = 0, right = nums.size() - 1; // Two pointers, one at the beginning and one at the end
        int count = 0; // Counter for the number of operations

        // Loop until the two pointers meet
        while (left < right) {
            int sum = nums[left] + nums[right]; // Calculate the sum of the two elements

            if (sum == k) { // If the sum equals k, we found a pair
                count++;    // Increment the count of operations
                left++;     // Move left pointer to the right
                right--;    // Move right pointer to the left
            } else if (sum < k) { // If the sum is less than k
                left++;           // Move left pointer to increase the sum
            } else {              // If the sum is greater than k
                right--;          // Move right pointer to decrease the sum
            }
        }
        return count; // Return the total count of operations
    }
};
