class Solution:
    # Helper function to check if a character is a vowel
    def isVowel(self, a: str) -> bool:
        return a in 'aeiou'

    # Function to find the maximum number of vowels in any substring of length k
    def maxVowels(self, s: str, k: int) -> int:
        n = len(s)
        count = 0
        max_vowels = 0

        # Initialize the count by counting vowels in the first 'k' characters
        for i in range(k):
            if self.isVowel(s[i]):
                count += 1

        # Set max_vowels to the initial count of vowels in the first window
        max_vowels = count

        # Slide the window across the string
        for j in range(k, n):
            # Add the vowel count of the new character entering the window
            count += 1 if self.isVowel(s[j]) else 0
            # Subtract the vowel count of the character that is now outside the window
            count -= 1 if self.isVowel(s[j - k]) else 0
            # Update max_vowels if the current count is greater
            max_vowels = max(max_vowels, count)

        return max_vowels
