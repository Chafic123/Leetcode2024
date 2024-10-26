class Solution:
    # Function to return an array where each element is the product of all elements except itself
    def productExceptSelf(self, nums):
        n = len(nums)
        
        left_products = [1] * n  # List to hold products of elements to the left of each index
        right_products = [1] * n  # List to hold products of elements to the right of each index
        answer = [1] * n  # List to store the final result
        
        # Compute the products of all elements to the left of each index
        for i in range(1, n):
            left_products[i] = left_products[i - 1] * nums[i - 1]
        
        # Compute the products of all elements to the right of each index
        for i in range(n - 2, -1, -1):
            right_products[i] = right_products[i + 1] * nums[i + 1]
        
        # Calculate the final answer by multiplying the left and right products
        for i in range(n):
            answer[i] = left_products[i] * right_products[i]
        
        return answer  # Return the result list
