#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    // Function to reverse only the vowels in a string
    string reverseVowels(string s) {
        int i = 0;  // Pointer starting from the beginning of the string
        int j = s.length() - 1;  // Pointer starting from the end of the string
        
        // While the two pointers have not crossed each other
        while (i < j) {
            // Move the left pointer until we find a vowel
            while (i < j && !isVowel(s[i])) {
                i++;
            }
            // Move the right pointer until we find a vowel
            while (i < j && !isVowel(s[j])) {
                j--;
            }
            
            // If we have found vowels at both pointers, swap them
            if (i < j) {
                swap(s[i], s[j]);
                i++;  // Move the left pointer forward
                j--;  // Move the right pointer backward
            }
        }
        
        return s;  // Return the modified string with vowels reversed
    }
};
