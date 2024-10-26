#include <vector>
using namespace std;

class Solution {
public:
    // Function to determine if 'n' flowers can be planted in the flowerbed
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();  // Get the size of the flowerbed
        int counter = 0;  // Counter to track how many flowers can be planted

        // Loop through each plot in the flowerbed
        for(int i = 0; i < size; i++) {
            // Check if the current spot is empty (0) and that its neighbors (if any) are also empty
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == size-1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;  // Place a flower in the current spot
                counter++;  // Increment the counter for planted flowers
                i++;  // Skip the next spot as flowers cannot be planted adjacent to each other
            }
        }

        // Return true if we can plant 'n' or more flowers, otherwise false
        return counter >= n;
    }
};
