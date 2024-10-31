class Solution {
    public String removeStars(String s) {
        StringBuilder result = new StringBuilder();  // Use StringBuilder for efficiency
        for (char c : s.toCharArray()) {  // Convert the string to a character array and iterate
            if (c == '*') {  // Check if the character is a star
                if (result.length() > 0)  // If the result is not empty
                    result.deleteCharAt(result.length() - 1);  // Remove the last character
            } else 
                result.append(c);  // Append the current character to the result
        }
        return result.toString();  // Convert StringBuilder to String and return
    }
}
