class Solution {
public:
    // Helper function to count paths with a given sum starting from the current node
    void CountPathSum(TreeNode* root, int targetSum, long long currentSum, int& count) {
        if (root == NULL) // Base case: if the node is null, return
            return;

        currentSum += root->val; // Add the current node's value to the current sum

        // Check if the current sum equals the target sum
        if (currentSum == targetSum) {
            count++; // Increment count if the current sum matches the target sum
        }

        // Recursively check the left and right subtrees
        CountPathSum(root->left, targetSum, currentSum, count);
        CountPathSum(root->right, targetSum, currentSum, count);
    }

    // Function to traverse the tree and start path sum counting from each node
    void Traverse(TreeNode* root, int targetSum, int& count) {
        if (root == NULL) // Base case: if the node is null, return
            return;

        // Count paths starting from the current node
        CountPathSum(root, targetSum, 0, count);

        // Recursively traverse the left and right children
        Traverse(root->left, targetSum, count);
        Traverse(root->right, targetSum, count);
    }

    // Main function to count the number of paths that sum to a target value
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0; // Initialize count of valid paths
        Traverse(root, targetSum, count); // Start traversing the tree
        return count; // Return the total count of paths with the target sum
    }
};
