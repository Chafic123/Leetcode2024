class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char a) {
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    }

    // Function to find the maximum number of vowels in any substring of length k
    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0, maxVowels = 0;
        
        // Initialize the count by counting vowels in the first 'k' characters
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) count++;
        }

        // Set maxVowels to the initial count of vowels in the first window
        maxVowels = count;
        
        // Slide the window across the string
        for (int j = k; j < n; j++) {
            // Add the vowel count of the new character entering the window
            count += isVowel(s[j]) ? 1 : 0;
            // Subtract the vowel count of the character that is now outside the window
            count -= isVowel(s[j - k]) ? 1 : 0;
            // Update maxVowels if the current count is greater
            maxVowels = max(count, maxVowels);
        }
        
        return maxVowels;
    }
};
