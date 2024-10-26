class Solution:
    # Function to check if the array contains an increasing triplet subsequence
    def increasingTriplet(self, nums):
        first = float('inf')  # Initialize to infinity
        second = float('inf')  # Initialize to infinity
        
        # Traverse through the list
        for num in nums:
            if num <= first:
                first = num  # Update 'first' if current number is smaller or equal
            elif num <= second:
                second = num  # Update 'second' if current number is smaller or equal but greater than 'first'
            else:
                return True  # If a number is greater than both 'first' and 'second', return True
        
        return False  # No increasing triplet found
