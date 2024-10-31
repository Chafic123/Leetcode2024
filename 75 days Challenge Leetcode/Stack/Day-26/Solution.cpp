#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;   // Stack to keep track of numbers
        stack<string> strStack; // Stack to keep track of strings
        string currentStr;      // The current decoded string
        int currentNum = 0;     // The current number being processed

        for (char ch : s) {
            if (isdigit(ch)) { // If the character is a digit
                currentNum = currentNum * 10 + (ch - '0'); // Build the number
            } else if (ch == '[') { // When we encounter a '['
                strStack.push(currentStr); // Push the current string onto the stack
                numStack.push(currentNum);   // Push the current number onto the stack
                currentStr = ""; // Reset current string
                currentNum = 0;  // Reset current number
            } else if (ch == ']') { // When we encounter a ']'
                string prevStr = strStack.top(); // Get the last string from the stack
                strStack.pop();
                int num = numStack.top(); // Get the last number from the stack
                numStack.pop();

                for (int i = 0; i < num; ++i) // Repeat the current string 'num' times
                    prevStr += currentStr;

                currentStr = prevStr; // Set the current string to the repeated string
            } else {
                currentStr += ch; // Add the character to the current string
            }
        }
        return currentStr; // Return the final decoded string
    }
};
