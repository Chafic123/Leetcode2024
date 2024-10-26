import java.util.*;

class Solution {
    // Function to return an array where each element is the product of all elements except itself
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        
        int[] left_products = new int[n];  // Array to hold products of elements to the left of each index
        int[] right_products = new int[n];  // Array to hold products of elements to the right of each index
        int[] answer = new int[n];  // Array to store the final result
        
        Arrays.fill(left_products, 1);  // Initialize arrays with 1
        Arrays.fill(right_products, 1);
        
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
}
