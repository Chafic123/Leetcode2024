from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        n = len(gain)
        prefix_sum = [0] * (n + 1) # +1 to include the initial altitude
        prefix_sum[0] = 0 # Starting altitude
        
        # Calculate prefix sum for each altitude after each gain
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + gain[i - 1] # Add gain[i-1] to previous altitude
        
        # Find the maximum altitude from the prefix_sum list
        max_altitude = max(prefix_sum) # max() finds the highest value in the list
        return max_altitude
