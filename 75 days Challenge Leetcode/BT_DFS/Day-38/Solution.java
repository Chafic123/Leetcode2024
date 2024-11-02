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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // Base case: if the current node is null or matches either p or q, return it
        if (root == null || root == p || root == q)
            return root;

        // Recursively search in the left and right subtrees
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        // If both left and right are non-null, it means p and q are found in different subtrees
        if (left != null && right != null)
            return root; // Current node is the LCA

        // Otherwise, return the non-null child (if any)
        return left != null ? left : right;
    }
}
