#include <vector>
using namespace std;

class Solution {
public:
    // Function to return an array where each element is the product of all elements except itself
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array
        
        vector<int> left_products(n, 1);   // Array to hold products of elements to the left of each index
        vector<int> right_products(n, 1);  // Array to hold products of elements to the right of each index
        vector<int> answer(n, 1);  // Array to store the final result
        
        // Compute the products of all elements to the left of each index
        for (int i = 1; i < n; i++) {
            left_products[i] = left_products[i - 1] * nums[i - 1];
        }
        
        // Compute the products of all elements to the right of each index
        for (int i = n - 2; i >= 0; i--) {
            right_products[i] = right_products[i + 1] * nums[i + 1];
        }
        
        // Calculate the final answer by multiplying the left and right products
        for (int i = 0; i < n; i++) {
            answer[i] = left_products[i] * right_products[i];
        }
      
        return answer;  // Return the result array
    }
};
