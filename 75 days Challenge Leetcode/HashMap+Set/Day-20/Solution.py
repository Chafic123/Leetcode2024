from typing import List, Set

class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        # to eliminate duplicates
        set1: Set[int] = set(nums1)
        set2: Set[int] = set(nums2)
        
        # Initialize lists to store unique elements for each input list
        dp = []
        dp1 = []

        # Find elements that are in set1 but not in set2
        for num in set1:
            if num not in set2:
                dp.append(num) # Add to result if unique to set1

        # Find elements that are in set2 but not in set1
        for num in set2:
            if num not in set1:
                dp1.append(num) # Add to result if unique to set2

        # Return a list of lists containing the unique elements for each input list
        return [dp, dp1]
