class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # Check if concatenating str1 + str2 is the same as str2 + str1
        # Ensures that the strings have a common divisor pattern
        if str1 + str2 == str2 + str1:
            # Return the substring from 0 to the GCD of the lengths of str1 and str2
            return str1[:self.gcd(len(str1), len(str2))]
        else:
            # If the concatenated strings are not equal, no common divisor exists
            return ""

    # Helper function to calculate the GCD of two integers
    def gcd(self, a: int, b: int) -> int:
        # Euclidean algorithm to compute GCD
        return a if b == 0 else self.gcd(b, a % b)
