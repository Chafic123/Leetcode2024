from collections import Counter

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        # Check if the words are of different lengths
        if len(word1) != len(word2):
            return False

        # Sets to store unique characters in each word
        set_word1 = set(word1)
        set_word2 = set(word2)

        # If the sets of characters are not the same, words can't be "close"
        if set_word1 != set_word2:
            return False

        # Count the frequency of each character in both words
        freq_word1 = Counter(word1)
        freq_word2 = Counter(word2)

        # Get frequency values and sort them
        freq_values1 = sorted(freq_word1.values())
        freq_values2 = sorted(freq_word2.values())

        # Compare the sorted frequency lists
        return freq_values1 == freq_values2
