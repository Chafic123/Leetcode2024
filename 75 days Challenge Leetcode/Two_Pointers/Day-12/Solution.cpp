class Solution {  
public:  
    int maxArea(vector<int>& height) {  
        int maxArea = 0; // Variable to store the maximum area found
        int start = 0, end = height.size() - 1; // Two pointers: start and end of the array

        // Loop until the two pointers meet
        while (start < end) {
            // Calculate the current height as the smaller of the two heights at the pointers
            int currentHeight = min(height[start], height[end]);
            // Calculate the width between the two pointers
            int currentWidth = end - start;
            // Calculate the area and update maxArea if this area is larger
            maxArea = max(maxArea, currentHeight * currentWidth);

            // Move the pointers to try and find a larger area
            if (height[start] < height[end]) 
                start++; // Move the left pointer to the right
            else 
                end--; // Move the right pointer to the left
        }
        return maxArea; // Return the maximum area found
    }  
};
