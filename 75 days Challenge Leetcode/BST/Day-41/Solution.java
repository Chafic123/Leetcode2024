class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        // Traverse the tree iteratively
        while (root != null && root.val != val) {
            // If target value is less than current node's value, move left
            if (val < root.val) {
                root = root.left;
            } else { // Otherwise, move right
                root = root.right;
            }
        }
        // Return the found node or null if the value was not in the tree
        return root;
    }
}
