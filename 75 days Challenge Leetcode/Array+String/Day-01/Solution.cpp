class Solution {
public:

    string mergeAlternately(string word1, string word2) {

        int len1 = word1.length();
        int len2 = word2.length();
        
    // to store the final result
        string result = "";

        // Determine the smaller length between the two strings
        int minlength = len1 < len2 ? len1 : len2;

        // Loop through the characters of both strings up to the length of the shorter one
        for (int i = 0; i < minlength; i++) {
            // Append the character from word1 followed by the character from word2
            result += word1[i];
            result += word2[i];
        }

        // Append the remaining characters from the longer string (if any)
        // If word1 is longer, append the rest of word1
        // If word2 is longer, append the rest of word2
        return (len1 > len2) ? result += word1.substr(minlength)
                            : result += word2.substr(minlength);
    }
};
