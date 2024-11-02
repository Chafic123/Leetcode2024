# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x=0, left=None, right=None):
        self.val = x  # Value of the node
        self.left = left  # Pointer to the left child
        self.right = right  # Pointer to the right child

class Solution:
    def __init__(self):
        self.count = 0  # Variable to keep track of the number of good nodes

    # Recursive helper function to count good nodes
    def countGoodNodes(self, root, maxVal):
        if root is None:  # Base case: if the node is null, return
            return

        # Check if the current node's value is greater than or equal to maxVal
        if root.val >= maxVal:
            self.count += 1  # Increment count of good nodes
            maxVal = root.val  # Update maxVal to the current node's value

        # Recursively count good nodes in the left and right subtrees
        self.countGoodNodes(root.left, maxVal)
        self.countGoodNodes(root.right, maxVal)

    # Public method to start the counting process from the root
    def goodNodes(self, root):
        if root is None:  # If the tree is empty, return 0
            return 0

        self.count = 0  # Initialize count to 0
        self.countGoodNodes(root, root.val)  # Start counting from the root node

        return self.count  # Return the total count of good nodes
