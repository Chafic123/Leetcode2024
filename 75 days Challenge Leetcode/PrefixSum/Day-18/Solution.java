import java.util.*;

class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;
        int[] prefixSum = new int[n + 1]; // +1 to include the initial altitude
        prefixSum[0] = 0; // Starting altitude
        
        // Calculate prefix sum for each altitude after each gain
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + gain[i - 1]; // Add gain[i-1] to previous altitude
        }

        // Find the maximum altitude from the prefixSum array
        int maxAltitude = Arrays.stream(prefixSum).max().getAsInt(); // max() returns an OptionalInt, so getAsInt() retrieves it
        return maxAltitude;
    }
}
