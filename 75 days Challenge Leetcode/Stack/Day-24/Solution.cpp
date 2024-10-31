#include <string>

class Solution {
public:
    string removeStars(string s) {
        string result;  
        for (char c : s) {  // Iterate through each character in the input string
            if (c == '*') {  // Check if the character is a star
                if (!result.empty())  // If the result string is not empty
                    result.pop_back();  // Remove the last character from the result
            } else 
                result.push_back(c);  // Add the current character to the result
        }
        return result;  // Return the final result
    }
};
