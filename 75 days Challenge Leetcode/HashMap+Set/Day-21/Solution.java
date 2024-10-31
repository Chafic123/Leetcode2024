import java.util.*;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        // to store the frequency of each element in arr
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : arr) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1); // Increment the count for each number
        }
        
        // Set to store unique occurrence counts
        Set<Integer> occurrences = new HashSet<>();
        
        // Check if each frequency count is unique
        for (int count : freqMap.values()) {
            // If the occurrence count already exists in the set, return false
            if (!occurrences.add(count)) {
                return false;
            }
        }
        
        // All occurrence counts are unique if we reach here
        return true;
    }
}
