#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> prefix_sum(n + 1); // +1 to include the initial altitude
        prefix_sum[0] = 0; // Starting altitude
        for (int i = 1; i <= n; i++) 
            prefix_sum[i] = prefix_sum[i - 1] + gain[i - 1]; // Add each gain to previous altitude
        return *max_element(prefix_sum.begin(), prefix_sum.end()); // Find the max altitude
    }
};
