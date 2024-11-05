class Solution:
    # Helper function to find the maximum value in the left subtree
    def find_max(self, root):
        # Traverse to the rightmost node to find the largest value
        while root.right:
            root = root.right
        return root.val

    def deleteNode(self, root, key):
        if not root:
            return None  
        
        if key < root.val:
            # Key is smaller, search in the left subtree
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            # Key is larger, search in the right subtree
            root.right = self.deleteNode(root.right, key)
        else:
            # Node with the given key is found
            if not root.left:
                # Case 1: Only right child or no children
                return root.right  # Replace node with its right child
            elif not root.right:
                # Case 2: Only left child
                return root.left  # Replace node with its left child
            else:
                # Case 3: Node with both children
                max_left = self.find_max(root.left)  # Find max in left subtree
                root.val = max_left  # Replace node's value with max from left subtree
                root.left = self.deleteNode(root.left, max_left)  # Delete max node in left subtree
                
        return root 
