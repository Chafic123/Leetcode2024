from typing import List

class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort() # Sort the list
        left, right = 0, len(nums) - 1 # Two pointers
        count = 0 # Count of operations

        # Loop until the two pointers meet
        while left < right:
            sum_ = nums[left] + nums[right] # Calculate the sum

            if sum_ == k: # If sum equals k
                count += 1 # Increment the count of operations
                left += 1  # Move left pointer
                right -= 1 # Move right pointer
            elif sum_ < k: # If sum is less than k
                left += 1  # Move left pointer to increase sum
            else: # If sum is greater than k
                right -= 1 # Move right pointer to decrease sum

        return count # Return total count
