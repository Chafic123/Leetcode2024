from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total_sum = sum(nums) # Calculate the total sum of all elements
        left_sum = 0 # Initialize left sum as 0
        
        # Iterate over the array and check if left sum equals right sum at each index
        for i in range(len(nums)):
            # If left sum equals right sum, return the current index
            if left_sum == total_sum - left_sum - nums[i]: 
                return i
            # Update left sum by adding the current element
            left_sum += nums[i]
        
        # If no pivot index is found, return -1
        return -1
