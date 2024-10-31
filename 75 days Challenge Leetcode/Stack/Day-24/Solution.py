class Solution:
    def removeStars(self, s: str) -> str:
        result = []  # Use a list to collect characters for efficiency
        for c in s:  # Iterate through each character in the input string
            if c == '*':  # Check if the character is a star
                if result:  # If the result list is not empty
                    result.pop()  # Remove the last character from the result
            else:
                result.append(c)  # Add the current character to the result
        return ''.join(result)  # Join the list into a string and return
