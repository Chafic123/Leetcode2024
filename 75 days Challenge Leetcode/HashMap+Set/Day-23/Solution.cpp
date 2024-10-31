#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> hashmap; // Map to store each row and its frequency
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();

        // Store each row in the map with its frequency count
        for (int i = 0; i < row; i++) {
            hashmap[grid[i]]++;
        }

        // Check each column against stored rows in the map
        for (int j = 0; j < col; j++) {
            vector<int> curr;

            // Create a vector for the current column
            for (int i = 0; i < row; i++) {
                curr.emplace_back(grid[i][j]);
            }

            // Increment answer by the count of this column vector in the map
            ans += hashmap[curr];
        }

        return ans;
    }
};
