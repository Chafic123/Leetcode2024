import java.util.Stack;

class Solution {
    // Function to reverse the order of words in a string
    public String reverseWords(String s) {
        Stack<String> stack = new Stack<>();  // Stack to hold words
        StringBuilder word = new StringBuilder();  // To accumulate characters
        StringBuilder result = new StringBuilder();  // Final result string
        
        // Iterate through each character in the input string
        for (char c : s.toCharArray()) {
            if (c != ' ') {  // If the character is not a space
                word.append(c);  // Add character to the current word
            } else if (word.length() > 0) {  // If space and current word is not empty
                stack.push(word.toString());  // Push the word into the stack
                word.setLength(0);  // Reset the word
            }
        }
        
        // Push the last word into the stack if there's one
        if (word.length() > 0) {
            stack.push(word.toString());
        }
        
        // Pop words from the stack and form the result string
        while (!stack.isEmpty()) {
            result.append(stack.pop());  // Add the top word from the stack to result
            if (!stack.isEmpty()) {
                result.append(" ");  // Add a space between words
            }
        }
        
        return result.toString();  // Return the reversed words string
    }
}
