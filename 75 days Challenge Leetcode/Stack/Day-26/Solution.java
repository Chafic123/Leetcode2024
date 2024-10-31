import java.util.Stack;

class Solution {
    public String decodeString(String s) {
        Stack<Integer> numStack = new Stack<>(); // Stack to keep track of numbers
        Stack<String> strStack = new Stack<>();   // Stack to keep track of strings
        StringBuilder currentStr = new StringBuilder(); // Current decoded string
        int currentNum = 0; // Current number being processed

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) { // If the character is a digit
                currentNum = currentNum * 10 + (ch - '0'); // Build the number
            } else if (ch == '[') { // When we encounter a '['
                strStack.push(currentStr.toString()); // Push the current string onto the stack
                numStack.push(currentNum); // Push the current number onto the stack
                currentStr = new StringBuilder(); // Reset current string
                currentNum = 0; // Reset current number
            } else if (ch == ']') { // When we encounter a ']'
                String prevStr = strStack.pop(); // Get the last string from the stack
                int num = numStack.pop(); // Get the last number from the stack

                for (int i = 0; i < num; i++) // Repeat the current string 'num' times
                    prevStr += currentStr.toString();

                currentStr = new StringBuilder(prevStr); // Set the current string to the repeated string
            } else {
                currentStr.append(ch); // Add the character to the current string
            }
        }
        return currentStr.toString(); // Return the final decoded string
    }
}
