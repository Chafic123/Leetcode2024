import java.util.List;

public class Solution {
    public boolean increasingTriplet(List<Integer> nums) {
        // Initialize two variables to the maximum integer value
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;

        // Loop through each number in the list
        for (int num : nums) {
            if (num <= first) { // if num is less than or equal to 'first'
                first = num;     // update 'first' to num
            } else if (num <= second) { // if num is greater than 'first' but less than or equal to 'second'
                second = num;    // update 'second' to num
            } else { // if we find a number greater than both 'first' and 'second'
                return true;     // we have found an increasing triplet, return true
            }
        }
        return false; // no increasing triplet was found, return false
    }
}
