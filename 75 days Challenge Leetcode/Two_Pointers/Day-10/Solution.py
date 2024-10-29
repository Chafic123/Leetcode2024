from typing import List

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        # Initialize two variables to represent the smallest and second smallest values
        first = float('inf')
        second = float('inf')

        # Loop through each number in the list
        for num in nums:
            if num <= first: # if num is less than or equal to 'first'
                first = num  # update 'first' to num
            elif num <= second: # if num is greater than 'first' but less than or equal to 'second'
                second = num # update 'second' to num
            else: # if we find a number greater than both 'first' and 'second'
                return True  # we have found an increasing triplet, return true
        return False # no increasing triplet was found, return false
