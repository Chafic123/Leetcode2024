from typing import Optional

class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:

        while root is not None and root.val != val:
            # If target value is less than current node's value, move left
            if val < root.val:
                root = root.left
            else: # Otherwise, move right
                root = root.right
        # Return the found node or None if the value was not in the tree
        return root
