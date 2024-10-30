class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0, leftSum = 0;
        
        // Calculate the total sum of all elements in the array
        for (int num : nums) totalSum += num;
        
        // Iterate over the array and check if left sum equals right sum at each index
        for (int i = 0; i < nums.size(); i++) {
            // If left sum equals right sum, return the current index
            if (leftSum == totalSum - leftSum - nums[i])  
                return i;
            // Update left sum by adding the current element
            leftSum += nums[i];
        }
        
        // If no pivot index is found, return -1
        return -1;
    }
};
