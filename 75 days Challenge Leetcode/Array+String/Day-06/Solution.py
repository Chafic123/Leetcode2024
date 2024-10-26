class Solution:
    # Function to reverse the order of words in a string
    def reverseWords(self, s: str) -> str:
        words = []  # List to hold words
        word = ''   # Temporary string to accumulate characters
        
        # Iterate through each character in the input string
        for char in s:
            if char != ' ':  # If the character is not a space
                word += char  # Add character to the current word
            elif word:  # If space and current word is not empty
                words.append(word)  # Append the word to the list
                word = ''  # Reset the word
        
        # Append the last word to the list if there's one
        if word:
            words.append(word)
        
        # Reverse the list of words and join them with a space
        return ' '.join(reversed(words))
