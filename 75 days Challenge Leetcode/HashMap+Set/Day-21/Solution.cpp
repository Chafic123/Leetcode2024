#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // to store the frequency of each element in arr
        map<int, int> mp;  
        for (int num : arr) {
            mp[num]++; 
        }
        
        // Set to track unique occurrence counts
        set<int> occurrences;
        
        // Check if each frequency count is unique
        for (const auto& pair : mp) {
            // If the occurrence count already exists in the set, return false
            if (occurrences.count(pair.second)) {
                return false;
            }
            // Insert the occurrence count into the set
            occurrences.insert(pair.second);
        }
        
        // All occurrence counts are unique if we reach here
        return true;
    }
};
