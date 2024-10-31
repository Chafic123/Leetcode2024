import java.util.*;

class Solution {
    public List<List<Integer>> findDifference(List<Integer> nums1, List<Integer> nums2) {
        // to eliminate duplicates
        Set<Integer> set1 = new HashSet<>(nums1);
        Set<Integer> set2 = new HashSet<>(nums2);
        
        // to store unique elements for each input list
        List<Integer> dp = new ArrayList<>();
        List<Integer> dp1 = new ArrayList<>();
        
        // Find elements that are in set1 but not in set2
        for (int num : set1) {
            if (!set2.contains(num)) {
                dp.add(num); // Add to the result list if the element is unique to set1
            }
        }

        // Find elements that are in set2 but not in set1
        for (int num : set2) {
            if (!set1.contains(num)) {
                dp1.add(num); // Add to the result list if the element is unique to set2
            }
        }

        return Arrays.asList(dp, dp1);
    }
}
