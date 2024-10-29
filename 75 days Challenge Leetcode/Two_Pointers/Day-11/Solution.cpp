class Solution {
public:
    bool isSubsequence(string s, string t) {
        int S = s.length(); // Length of the string 's'
        int T = t.length(); // Length of the string 't'
        
        // If 's' is empty, it's automatically a subsequence of any string
        if (s.empty())  
            return true;

        // If 's' is longer than 't', it can't be a subsequence
        if (S > T)
            return false;

        int j = 0; // Pointer to track position in 's'

        // Loop through each character in 't' with 'i' and check against 's'
        for (int i = 0; i < T && j < S; i++) {
            if (s[j] == t[i]) // If characters match
                j++;          // Move to the next character in 's'
        }

        // If 'j' has moved to the end of 's', it means all characters in 's' were found in 't' in order
        return j == S;
    }
};
