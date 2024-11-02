# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x  # Value of the node
        self.left = None  # Pointer to the left child
        self.right = None  # Pointer to the right child

class Solution:
    def __init__(self):
        self.maxLength = 0  # Variable to keep track of the maximum zigzag length

    # Recursive function to explore the tree in a zigzag pattern
    def zigZag(self, node, isLeft, length):
        if node is None:  # Base case: if the node is null, return
            return

        self.maxLength = max(self.maxLength, length)  # Update maxLength if the current length is greater

        # If the current direction is left, move to the right child and switch direction
        if isLeft:
            self.zigZag(node.right, False, length + 1)  # Move right
            self.zigZag(node.left, True, 1)  # Start a new zigzag from the left child
        else:
            self.zigZag(node.left, True, length + 1)  # Move left
            self.zigZag(node.right, False, 1)  # Start a new zigzag from the right child

    # Main function to start the zigzag traversal
    def longestZigZag(self, root):
        if root is None:  # If the root is null, return 0
            return 0

        # Start the zigzag traversal from the root's left and right children
        self.zigZag(root.left, True, 1)  
        self.zigZag(root.right, False, 1)
        
        return self.maxLength  # Return the maximum zigzag length found
