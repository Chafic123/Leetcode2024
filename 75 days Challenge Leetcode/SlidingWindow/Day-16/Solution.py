class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left = 0

        # Iterate with the right pointer
        for right in range(n):
            # Decrease k if we encounter a 0, as it would need flipping to become 1
            if nums[right] == 0:
                k -= 1

            # If k goes below 0, we have exceeded the number of allowed flips
            if k < 0:
                # Increment k if the left pointer is at a 0, restoring one flip allowance
                if nums[left] == 0:
                    k += 1
                # Move the left pointer to shrink the window
                left += 1

        # The length of the longest valid subarray is the window size
        return right - left
