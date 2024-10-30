class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        # Return 0 if the input array is empty
        if n == 0:
            return 0

        start = 0  # Initialize start pointer for the sliding window
        num_zeroes = 0  # Count of zeroes in the current window
        max_length = 0  # Maximum length of the subarray found

        # Iterate with the end pointer to expand the window
        for end in range(n):
            # Count the number of zeroes encountered
            if nums[end] == 0:
                num_zeroes += 1

            # If there are more than one zero, shrink the window from the start
            while num_zeroes > 1:
                # If the start element is a zero, decrease the count of zeroes
                if nums[start] == 0:
                    num_zeroes -= 1
                start += 1  # Move the start pointer to the right

            # Update the maximum length of the subarray (excluding at most one zero)
            max_length = max(max_length, end - start)

        return max_length  # Return the maximum length found
