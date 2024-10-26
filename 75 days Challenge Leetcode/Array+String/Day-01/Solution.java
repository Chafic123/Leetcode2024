class Solution {
    public String mergeAlternately(String word1, String word2) {
        // Get the lengths of both input strings
        int len1 = word1.length();
        int len2 = word2.length();
        
        // Initialize a StringBuilder to store the result (better performance than String concatenation)
        StringBuilder result = new StringBuilder();
        
        // Find the smaller length between word1 and word2
        int minlength = Math.min(len1, len2);

        // Loop through both strings alternately until the end of the shorter one
        for (int i = 0; i < minlength; i++) {
            // Append characters alternately from both strings
            result.append(word1.charAt(i));
            result.append(word2.charAt(i));
        }

        // Append remaining characters from the longer string
        if (len1 > len2) {
            result.append(word1.substring(minlength)); // Remaining characters from word1
        } else {
            result.append(word2.substring(minlength)); // Remaining characters from word2
        }

        // Convert StringBuilder back to String and return
        return result.toString();
    }
}
