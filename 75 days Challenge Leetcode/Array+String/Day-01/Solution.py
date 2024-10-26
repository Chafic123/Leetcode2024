class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        # Get the lengths of both input strings
        len1 = len(word1)
        len2 = len(word2)
        
        # Initialize an empty list to store the merged result (lists are more efficient for multiple concatenations)
        result = []
        
        # Find the smaller length between word1 and word2
        minlength = min(len1, len2)

        # Loop through both strings alternately until the end of the shorter one
        for i in range(minlength):
            # Append characters alternately from both strings
            result.append(word1[i])
            result.append(word2[i])

        # Append remaining characters from the longer string
        if len1 > len2:
            result.append(word1[minlength:])  # Remaining characters from word1
        else:
            result.append(word2[minlength:])  # Remaining characters from word2

        # Join the list into a single string and return
        return ''.join(result)
