from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0  # Variable to store the maximum area found
        start, end = 0, len(height) - 1  # Two pointers: start and end of the list

        # Loop until the two pointers meet
        while start < end:
            # Calculate the current height as the smaller of the two heights at the pointers
            current_height = min(height[start], height[end])
            # Calculate the width between the two pointers
            current_width = end - start
            # Calculate the area and update max_area if this area is larger
            max_area = max(max_area, current_height * current_width)

            # Move the pointers to try and find a larger area
            if height[start] < height[end]:
                start += 1  # Move the left pointer to the right
            else:
                end -= 1  # Move the right pointer to the left

        return max_area  # Return the maximum area found
