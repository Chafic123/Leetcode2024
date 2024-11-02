# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x  # Value of the node
        self.left = None  # Pointer to the left child
        self.right = None  # Pointer to the right child

class Solution:
    # Function to find the lowest common ancestor of two nodes in a binary tree
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # Base case: if the current node is null or matches either p or q, return it
        if root is None or root == p or root == q:
            return root

        # Recursively search in the left and right subtrees
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        # If both left and right are non-null, it means p and q are found in different subtrees
        if left is not None and right is not None:
            return root  # Current node is the LCA

        # Otherwise, return the non-null child (if any)
        return left if left is not None else right
