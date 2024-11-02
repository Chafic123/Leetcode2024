/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; // Value of the node
 *     TreeNode *left; // Pointer to the left child
 *     TreeNode *right; // Pointer to the right child
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Constructor
 * };
 */
class Solution {
public:
    // Function to find the lowest common ancestor of two nodes in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the current node is null or matches either p or q, return it
        if (root == NULL || root == p || root == q)
            return root;

        // Recursively search in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-null, it means p and q are found in different subtrees
        if (left != NULL && right != NULL)
            return root; // Current node is the LCA

        // Otherwise, return the non-null child (if any)
        return left != NULL ? left : right;
    }
};
