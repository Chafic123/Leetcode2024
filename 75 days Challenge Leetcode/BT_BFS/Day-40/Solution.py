from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        if not root:
            return 0  # Handle edge case where root is null

        temp = deque([root])  # Queue to traverse levels of the tree, starting with the root node
        level = 1             # Tracks the current level
        maxLevel = 1          # Tracks the level with the maximum sum
        max_sum = root.val    # Initialize max_sum with the root node's value

        while temp:
            levelSize = len(temp)  # Number of nodes at the current level
            levelSum = 0           # Sum of values at the current level

            # Traverse all nodes at the current level
            for _ in range(levelSize):
                node = temp.popleft()
                levelSum += node.val  # Add the node's value to levelSum

                # Add child nodes for the next level
                if node.left:
                    temp.append(node.left)
                if node.right:
                    temp.append(node.right)

            # Check if current level has a greater sum than max_sum
            if levelSum > max_sum:
                max_sum = levelSum
                maxLevel = level

            level += 1  # Move to the next level

        return maxLevel  # Return the level with the maximum sum
