class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        
        # Calculate the sum of the first 'k' elements to form the initial window
        window_sum = sum(nums[:k])
        
        # Set max_sum to the sum of the initial window
        max_sum = window_sum

        # Slide the window across the array
        for i in range(k, n):
            # Add the next element and remove the element that is now outside the window
            window_sum += nums[i] - nums[i - k]
            # Update max_sum if the current window sum is greater
            max_sum = max(max_sum, window_sum)

        # Return the maximum average by dividing the max_sum by 'k'
        return max_sum / k
