/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: if the node is null, its depth is 0.
        if (!root) return 0;

        // Recursively find the depth of the left and right subtrees.
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);

        // The depth of the current node is 1 (for the current node) plus the maximum depth of the left or right subtree.
        return 1 + max(left_depth, right_depth);
    }
};
