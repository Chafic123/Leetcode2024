#include <vector>
#include <climits> // for INT_MIN
using namespace std;

class Solution {
public:
    // Function to determine which kids can have the greatest number of candies
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();  // Number of kids
        vector<bool> output(n);  // Boolean vector to store the result
        int max = INT_MIN;       // Initialize the max to the smallest possible integer
        
        // First loop: Find the maximum number of candies any kid currently has
        for (int i = 0; i < n; i++) {
            if (candies[i] > max) max = candies[i];
        }
        
        // Second loop: Determine if each kid can have the greatest number of candies
        // after receiving the extraCandies
        for (int i = 0; i < n; i++) {
            output[i] = (candies[i] + extraCandies >= max);
        }
        
        return output;  // Return the vector
    }
};
