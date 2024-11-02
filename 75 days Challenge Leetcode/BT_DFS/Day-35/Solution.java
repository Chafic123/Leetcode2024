// Definition for a binary tree node.
class TreeNode {
    int val; 
    TreeNode left; 
    TreeNode right; 

    TreeNode() {
        this.val = 0;
        this.left = null;
        this.right = null;
    }

    TreeNode(int x) {
        this.val = x;
        this.left = null;
        this.right = null;
    }

    TreeNode(int x, TreeNode left, TreeNode right) {
        this.val = x;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    
    int count; 

    // Recursive helper function to count good nodes
    private void countGoodNodes(TreeNode root, int maxVal) {
        if (root == null) // Base case: if the node is null, return
            return;

        // Check if the current node's value is greater than or equal to maxVal
        if (root.val >= maxVal) {
            count++; // Increment count of good nodes
            maxVal = root.val; // Update maxVal to the current node's value
        }

        // Recursively count good nodes in the left and right subtrees
        countGoodNodes(root.left, maxVal);
        countGoodNodes(root.right, maxVal);
    }

    public int goodNodes(TreeNode root) {
        if (root == null) // If the tree is empty, return 0
            return 0;

        count = 0; // Initialize count to 0
        countGoodNodes(root, root.val); // Start counting from the root node

        return count; // Return the total count of good nodes
    }
}
