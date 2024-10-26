#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Function to reverse the order of words in a string
    string reverseWords(string s) {
        stack<string> st;  // Stack to hold the words
        string str = "";   // Temporary string to accumulate characters
        string result = "";  // Final result string
        
        // Iterate through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {  // If the character is not a space
                str += s[i];    // Add character to the current word
            } else if (!str.empty()) {  // If space and current word is not empty
                st.push(str);  // Push the word into the stack
                str = "";      // Reset the word
            }
        }
        
        // Push the last word into the stack if there's one
        if (!str.empty()) 
            st.push(str);
        
        // Pop words from the stack and form the result string
        while (!st.empty()) {
            result += st.top();  // Add the top word from the stack to result
            st.pop();  // Remove the word from the stack
            if (!st.empty()) 
                result += " ";  // Add a space between words
        }
        
        return result;  // Return the reversed words string
    }
};
