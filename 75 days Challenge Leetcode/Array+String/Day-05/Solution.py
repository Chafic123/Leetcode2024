class Solution:
    # Helper function to check if a character is a vowel
    def isVowel(self, c: str) -> bool:
        return c in 'aeiouAEIOU'
    
    # Function to reverse only the vowels in a string
    def reverseVowels(self, s: str) -> str:
        s = list(s)  # Convert the string to a list of characters
        i, j = 0, len(s) - 1  # Two pointers starting from the beginning and end
        
        # While the two pointers have not crossed each other
        while i < j:
            # Move the left pointer until we find a vowel
            while i < j and not self.isVowel(s[i]):
                i += 1
            # Move the right pointer until we find a vowel
            while i < j and not self.isVowel(s[j]):
                j -= 1
            
            # If we have found vowels at both pointers, swap them
            if i < j:
                s[i], s[j] = s[j], s[i]
                i += 1  # Move the left pointer forward
                j -= 1  # Move the right pointer backward
        
        return ''.join(s)  # Convert the list back to a string
