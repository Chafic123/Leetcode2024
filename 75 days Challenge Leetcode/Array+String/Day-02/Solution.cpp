#include <string>
using namespace std;

class Solution {
public:
    // Function to find the greatest common divisor (GCD) of two strings
    string gcdOfStrings(string str1, string str2) {
        // Check if concatenating str1 + str2 is the same as str2 + str1
        // This ensures that the strings have a common divisor pattern
        if (str1 + str2 == str2 + str1) {
            // Return the substring from 0 to the GCD of the lengths of str1 and str2
            return str1.substr(0, gcd(str1.length(), str2.length()));
        } else {
            // If the concatenated strings are not equal, no common divisor exists
            return ""; 
        }
    }
}