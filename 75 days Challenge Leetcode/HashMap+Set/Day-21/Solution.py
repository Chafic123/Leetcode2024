from typing import List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        # to store the frequency of each element in arr
        freq_map = {}
        for num in arr:
            freq_map[num] = freq_map.get(num, 0) + 1 # Increment count for each number
        
        # Set to track unique occurrence counts
        occurrences = set()
        
        # Check if each frequency count is unique
        for count in freq_map.values():
            # If the occurrence count already exists in the set, return False
            if count in occurrences:
                return False
            occurrences.add(count)
        
        # All occurrence counts are unique if we reach here
        return True
