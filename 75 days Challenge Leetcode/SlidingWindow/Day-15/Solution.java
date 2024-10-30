class Solution {
    // Helper function to check if a character is a vowel
    private boolean isVowel(char a) {
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    }

    // Function to find the maximum number of vowels in any substring of length k
    public int maxVowels(String s, int k) {
        int n = s.length();
        int count = 0, maxVowels ;
        
        // Initialize the count by counting vowels in the first 'k' characters
        for (int i = 0; i < k; i++) {
            if (isVowel(s.charAt(i))) count++;
        }

        // Set maxVowels to the initial count of vowels in the first window
        maxVowels = count;

        // Slide the window across the string
        for (int j = k; j < n; j++) {
            // Add the vowel count of the new character entering the window
            count += isVowel(s.charAt(j)) ? 1 : 0;
            // Subtract the vowel count of the character that is now outside the window
            count -= isVowel(s.charAt(j - k)) ? 1 : 0;
            // Update maxVowels if the current count is greater
            maxVowels = Math.max(count, maxVowels);
        }

        return maxVowels;
    }
}
