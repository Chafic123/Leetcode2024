# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # Helper function to collect all leaf nodes of a tree
    def getLeaves(self, root, leaves):
        if not root:
            return
        
        if not root.left and not root.right:  # Leaf node
            leaves.append(root.val)
            return

        self.getLeaves(root.left, leaves)
        self.getLeaves(root.right, leaves)

    def leafSimilar(self, root1, root2):
        leaves1 = []
        leaves2 = []
        self.getLeaves(root1, leaves1)
        self.getLeaves(root2, leaves2)
        return leaves1 == leaves2  # Compare leaf sequences
