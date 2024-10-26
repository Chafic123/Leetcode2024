class Solution {
    public String gcdOfStrings(String str1, String str2) {
        // Check if concatenating str1 + str2 is the same as str2 + str1
        // Ensures that the strings have a common divisor pattern
        if ((str1 + str2).equals(str2 + str1)) {
            // Return the substring from 0 to the GCD of the lengths of str1 and str2
            return str1.substring(0, gcd(str1.length(), str2.length()));
        } else {
            // If the concatenated strings are not equal, no common divisor exists
            return ""; 
        }
    }

    // Helper function to calculate the GCD of two integers
    private int gcd(int a, int b) {
        // Euclidean algorithm to compute GCD
        return b == 0 ? a : gcd(b, a % b);
    }
}
