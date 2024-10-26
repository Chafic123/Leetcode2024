import java.util.*;

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int n = candies.length;  // Number of kids
        List<Boolean> output = new ArrayList<>(n);  // Boolean list to store the result
        int max = Integer.MIN_VALUE;  // Initialize the max to the smallest possible integer

        // First loop: Find the maximum number of candies any kid currently has
        for (int candy : candies) {
            if (candy > max) max = candy;
        }

        // Second loop: Determine if each kid can have the greatest number of candies
        // after receiving the extraCandies
        for (int candy : candies) {
            output.add(candy + extraCandies >= max);
        }

        return output;  // Return the boolean list
    }
}
