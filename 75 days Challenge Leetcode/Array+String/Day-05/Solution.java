class Solution {
    // Helper function to check if a character is a vowel
    public boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    // Function to reverse only the vowels in a string
    public String reverseVowels(String s) {
        char[] arr = s.toCharArray();  // Convert the string to a char array
        int i = 0;  // Pointer starting from the beginning
        int j = arr.length - 1;  // Pointer starting from the end
        
        // While the two pointers have not crossed each other
        while (i < j) {
            // Move the left pointer until we find a vowel
            while (i < j && !isVowel(arr[i])) {
                i++;
            }
            // Move the right pointer until we find a vowel
            while (i < j && !isVowel(arr[j])) {
                j--;
            }
            
            // If we have found vowels at both pointers, swap them
            if (i < j) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;  // Move the left pointer forward
                j--;  // Move the right pointer backward
            }
        }
        
        return new String(arr);  // Convert the char array back to a string
    }
}
