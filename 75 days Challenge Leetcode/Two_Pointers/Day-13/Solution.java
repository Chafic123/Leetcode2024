import java.util.Arrays;

public class Solution {
    public int maxOperations(int[] nums, int k) {
        Arrays.sort(nums); // Sort the array
        int left = 0, right = nums.length - 1; // Two pointers
        int count = 0; // Count of operations

        // Loop until the two pointers meet
        while (left < right) {
            int sum = nums[left] + nums[right]; // Calculate the sum

            if (sum == k) { // If sum equals k
                count++;    // Increment the count of operations
                left++;     // Move left pointer
                right--;    // Move right pointer
            } else if (sum < k) { // If sum is less than k
                left++; // Move left pointer to increase sum
            } else { // If sum is greater than k
                right--; // Move right pointer to decrease sum
            }
        }
        return count; // Return total count
    }
}
