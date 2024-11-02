# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x  # Value of the node
        self.left = None  # Pointer to the left child
        self.right = None  # Pointer to the right child

class Solution:
    # Helper function to count paths with a given sum starting from the current node
    def countPathSum(self, root, targetSum, currentSum, count):
        if root is None:  # Base case: if the node is null, return
            return

        currentSum += root.val  # Add the current node's value to the current sum

        # Check if the current sum equals the target sum
        if currentSum == targetSum:
            count[0] += 1  # Increment count if the current sum matches the target sum

        # Recursively check the left and right subtrees
        self.countPathSum(root.left, targetSum, currentSum, count)
        self.countPathSum(root.right, targetSum, currentSum, count)

    # Function to traverse the tree and start path sum counting from each node
    def traverse(self, root, targetSum, count):
        if root is None:  # Base case: if the node is null, return
            return

        # Count paths starting from the current node
        self.countPathSum(root, targetSum, 0, count)

        # Recursively traverse the left and right children
        self.traverse(root.left, targetSum, count)
        self.traverse(root.right, targetSum, count)

    # Main function to count the number of paths that sum to a target value
    def pathSum(self, root, targetSum):
        count = [0]  # Use a list to store count (to allow pass-by-reference)
        self.traverse(root, targetSum, count)  # Start traversing the tree
        return count[0]  # Return the total count of paths with the target sum
