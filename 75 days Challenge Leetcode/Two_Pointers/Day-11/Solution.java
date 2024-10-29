public class Solution {
    public boolean isSubsequence(String s, String t) {
        int S = s.length(); // Length of the string 's'
        int T = t.length(); // Length of the string 't'
        
        // If 's' is empty, it's automatically a subsequence of any string
        if (s.isEmpty()) 
            return true;

        // If 's' is longer than 't', it can't be a subsequence
        if (S > T)
            return false;

        // Pointer 'j' to track position in 's'
        int j = 0;

        // Loop through each character in 't' with 'i' and check with 's'
        for (int i = 0; i < T && j < S; i++) {
            // If characters match, move 'j' to the next character in 's'
            if (s.charAt(j) == t.charAt(i)) 
                j++;
        }

        // If 'j' has moved to the end of 's', it means all characters in 's' were found in 't' in order
        return j == S;
    }
}
