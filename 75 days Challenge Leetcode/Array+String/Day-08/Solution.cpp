#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to check if the array contains an increasing triplet subsequence
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;  // Initialize two variables to store the smallest and second smallest numbers
        
        // Traverse through the array
        for (int num : nums) {
            if (num <= first) {
                first = num;  // Update 'first' if current number is smaller or equal
            } else if (num <= second) {
                second = num;  // Update 'second' if current number is smaller or equal but greater than 'first'
            } else {
                return true;  // If a number is greater than both 'first' and 'second', an increasing triplet exists
            }
        }
        
        return false;  // No increasing triplet found
    }
};
