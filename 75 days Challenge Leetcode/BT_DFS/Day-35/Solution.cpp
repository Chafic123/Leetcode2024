/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; // Value of the node
 *     TreeNode *left; // Pointer to the left child
 *     TreeNode *right; // Pointer to the right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor with value and children
 * };
 */

class Solution {
    int count; // Variable to keep track of the number of good nodes

private:
    // Recursive helper function to count good nodes
    void countGoodNodes(TreeNode* root, int maxVal) {
        if (root == NULL) // Base case: if the node is null, return
            return;

        // Check if the current node's value is greater than or equal to maxVal
        if (root->val >= maxVal) {
            count++; // Increment count of good nodes
            maxVal = root->val; // Update maxVal to the current node's value
        }

        // Recursively count good nodes in the left and right subtrees
        countGoodNodes(root->left, maxVal);
        countGoodNodes(root->right, maxVal);
    }

public:
    // Public method to start the counting process from the root
    int goodNodes(TreeNode* root) {
        if (root == NULL) // If the tree is empty, return 0
            return 0;

        count = 0; // Initialize count to 0
        countGoodNodes(root, root->val); // Start counting from the root node

        return count; // Return the total count of good nodes
    }
};
