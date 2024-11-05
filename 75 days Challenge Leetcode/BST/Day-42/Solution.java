class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    // Helper function to find the maximum value in the left subtree
    private int findMax(TreeNode root) {
        // Traverse to the rightmost node to get the maximum value
        while (root.right != null) {
            root = root.right;
        }
        return root.val;
    }

    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;  

        if (key < root.val) {
            // If key is less, go to the left subtree
            root.left = deleteNode(root.left, key);
        } else if (key > root.val) {
            // If key is greater, go to the right subtree
            root.right = deleteNode(root.right, key);
        } else {
            // Node to delete is found
            if (root.left == null) {
                // Case 1: Only right child or no children
                return root.right;  // Return the right child to replace current node
            } else if (root.right == null) {
                // Case 2: Only left child
                return root.left;  // Return the left child to replace current node
            } else {
                // Case 3: Node with two children
                int maxLeft = findMax(root.left);  // Get max value from left subtree
                root.val = maxLeft;  // Replace node's value with max from left subtree
                root.left = deleteNode(root.left, maxLeft);  // Delete max node in left subtree
            }
        }
        return root;  
    }
}
