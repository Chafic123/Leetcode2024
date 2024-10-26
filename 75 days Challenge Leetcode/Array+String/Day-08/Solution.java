class Solution {
    // Function to check if the array contains an increasing triplet subsequence
    public boolean increasingTriplet(int[] nums) {
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;  // Initialize variables to store smallest and second smallest numbers
        
        // Traverse through the array
        for (int num : nums) {
            if (num <= first) {
                first = num;  // Update 'first' if current number is smaller or equal
            } else if (num <= second) {
                second = num;  // Update 'second' if current number is smaller or equal but greater than 'first'
            } else {
                return true;  // If a number is greater than both 'first' and 'second', return true
            }
        }
        
        return false;  // No increasing triplet found
    }
}
