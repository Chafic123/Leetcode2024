#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // to eliminate duplicates
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        // to store the unique elements from each list
        vector<int> dp;  // store elements unique to nums1
        vector<int> dp1; // store elements unique to nums2

        // Find elements in set1 that are not in set2
        for (int num : set1) {
            if (set2.count(num) == 0) { // If num is not in set2
                dp.push_back(num);      // Add it to dp (unique to nums1)
            }
        }

        // Find elements in set2 that are not in set1
        for (int num : set2) {
            if (set1.count(num) == 0) { // If num is not in set1
                dp1.push_back(num);     // Add it to dp1 (unique to nums2)
            }
        }

        // Return a vector of vectors containing the unique elements for each input vector
        return {dp, dp1};
    }
};
