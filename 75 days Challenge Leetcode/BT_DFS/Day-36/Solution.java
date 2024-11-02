class TreeNode {
    int val; 
    TreeNode left;
    TreeNode right; 

    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }
}

class Solution {

    private void countPathSum(TreeNode root, int targetSum, long currentSum, int[] count) {
        if (root == null) // Base case: if the node is null, return
            return;

        currentSum += root.val; // Add the current node's value to the current sum

        // Check if the current sum equals the target sum
        if (currentSum == targetSum) {
            count[0]++; // Increment count if the current sum matches the target sum
        }

        // Recursively check the left and right subtrees
        countPathSum(root.left, targetSum, currentSum, count);
        countPathSum(root.right, targetSum, currentSum, count);
    }

    private void traverse(TreeNode root, int targetSum, int[] count) {
        if (root == null) // Base case: if the node is null, return
            return;

        // Count paths starting from the current node
        countPathSum(root, targetSum, 0, count);

        // Recursively traverse the left and right children
        traverse(root.left, targetSum, count);
        traverse(root.right, targetSum, count);
    }

    public int pathSum(TreeNode root, int targetSum) {
        int[] count = new int[1]; // Use an array to store count (since Java doesn't support pass-by-reference)
        traverse(root, targetSum, count); // Start traversing the tree
        return count[0]; // Return the total count of paths with the target sum
    }
}