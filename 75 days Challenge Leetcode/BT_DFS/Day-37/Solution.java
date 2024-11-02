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
    int maxLength = 0; // Variable to keep track of the maximum zigzag length

    // Recursive function to explore the tree in a zigzag pattern
    private void zigZag(TreeNode node, boolean isLeft, int length) {
        if (node == null) return; // Base case: if the node is null, return

        maxLength = Math.max(maxLength, length); // Update maxLength if the current length is greater

        // If the current direction is left, move to the right child and switch direction
        if (isLeft) {
            zigZag(node.right, false, length + 1); // Move right
            zigZag(node.left, true, 1); // Start a new zigzag from the left child
        } else {
            zigZag(node.left, true, length + 1); // Move left
            zigZag(node.right, false, 1); // Start a new zigzag from the right child
        }
    }

    public int longestZigZag(TreeNode root) {
        if (root == null) return 0; // If the root is null, return 0

        // Start the zigzag traversal from the root's left and right children
        zigZag(root.left, true, 1);  
        zigZag(root.right, false, 1);
        
        return maxLength; // Return the maximum zigzag length found
    }
}
