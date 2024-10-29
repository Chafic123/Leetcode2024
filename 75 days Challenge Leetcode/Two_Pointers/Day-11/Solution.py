class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        S = len(s)  # Length of string 's'
        T = len(t)  # Length of string 't'

        # If 's' is empty, it's automatically a subsequence of any string
        if not s:
            return True

        # If 's' is longer than 't', it can't be a subsequence
        if S > T:
            return False

        # Pointer 'j' to track position in 's'
        j = 0

        # Loop through each character in 't' with 'i' and check with 's'
        for i in range(T):
            if j < S and s[j] == t[i]:  # If characters match, move 'j' to the next character in 's'
                j += 1

        # If 'j' has moved to the end of 's', it means all characters in 's' were found in 't' in order
        return j == S
