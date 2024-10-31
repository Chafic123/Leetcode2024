#include <unordered_map>
#include <set>
#include <algorithm> // for sorting
#include <vector>    // for storing frequency counts

class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if (word1.length() != word2.length()) return false;

        // Sets to store unique characters in each word
        set<char> setWord1, setWord2;
        
        // Maps to store the frequency of each character in each word
        unordered_map<char, int> freqWord1, freqWord2;

        // Populate set and frequency map for word1
        for (char c : word1) {
            setWord1.insert(c);   // Add character to set
            freqWord1[c]++;       // Increment frequency count in map
        }

        // Populate set and frequency map for word2
        for (char c : word2) {
            setWord2.insert(c);   // Add character to set
            freqWord2[c]++;       // Increment frequency count in map
        }

        // If the sets of characters are not the same, words can't be "close"
        if (setWord1 != setWord2) return false;

        // Vectors to store the frequency counts of each character
        vector<int> freqValues1, freqValues2;
        
        // Add all frequency counts from freqWord1 to freqValues1
        for (auto& kv : freqWord1) {
            freqValues1.push_back(kv.second);
        }

        // Add all frequency counts from freqWord2 to freqValues2
        for (auto& kv : freqWord2) {
            freqValues2.push_back(kv.second);
        }

        // Sort both frequency vectors to compare them
        sort(freqValues1.begin(), freqValues1.end());
        sort(freqValues2.begin(), freqValues2.end());

        // Compare the frequency distributions; they must match for words to be "close"
        return freqValues1 == freqValues2;
    }
};
