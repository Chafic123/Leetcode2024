class Solution:
    def compress(self, chars):
        i = 0  # Read pointer
        r = 0  # Write pointer
        size = len(chars)  # Total size of the input list
        
        while i < size:
            counter = 1  # Start counting repeated characters
            while i < size - 1 and chars[i] == chars[i + 1]:  # Count consecutive repeated characters
                counter += 1
                i += 1
            chars[r] = chars[i]  # Write the character at index r
            r += 1
            i += 1
            
            if counter > 1:  # If there are repetitions
                for digit in str(counter):  # Write each digit of the count back into the list
                    chars[r] = digit
                    r += 1
        
        return r  # Return the new length of the list after compression
