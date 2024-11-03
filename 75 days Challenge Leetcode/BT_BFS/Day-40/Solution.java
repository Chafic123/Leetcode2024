import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int maxLevelSum(TreeNode root) {
        if (root == null) return 0; // Handle edge case where root is null

        Queue<TreeNode> temp = new LinkedList<>(); // Queue to traverse levels of the tree
        temp.add(root);                            // Start BFS traversal with the root node

        int level = 1;       // Tracks the current level
        int maxLevel = 1;    // Tracks the level with the maximum sum
        int maxSum = root.val; // Initialize maxSum with the root node's value

        while (!temp.isEmpty()) {
            int levelSize = temp.size(); // Number of nodes at the current level
            int levelSum = 0;            // Sum of values at the current level

            // Traverse all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = temp.poll();
                levelSum += node.val;   // Add the node's value to levelSum

                // Add child nodes for the next level
                if (node.left != null) temp.add(node.left);
                if (node.right != null) temp.add(node.right);
            }

            // Check if current level has a greater sum than maxSum
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = level;
            }

            level++; // Move to the next level
        }

        return maxLevel; // Return the level with the maximum sum
    }
}
