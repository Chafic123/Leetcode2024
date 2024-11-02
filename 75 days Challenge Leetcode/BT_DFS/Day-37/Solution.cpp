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
public:
    int maxLength = 0; // Variable to keep track of the maximum zigzag length

    // Recursive function to explore the tree in a zigzag pattern
    void zigZag(TreeNode* node, bool isLeft, int length) {
        if (node == nullptr) return; // Base case: if the node is null, return

        maxLength = max(maxLength, length); // Update maxLength if the current length is greater

        // If the current direction is left, move to the right child and switch direction
        if (isLeft) {
            zigZag(node->right, false, length + 1); // Move right
            zigZag(node->left, true, 1); // Start a new zigzag from the left child
        } else {
            zigZag(node->left, true, length + 1); // Move left
            zigZag(node->right, false, 1); // Start a new zigzag from the right child
        }
    }

    // Main function to start the zigzag traversal
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0; // If the root is null, return 0

        // Start the zigzag traversal from the root's left and right children
        zigZag(root->left, true, 1);  
        zigZag(root->right, false, 1);
        
        return maxLength; // Return the maximum zigzag length found
    }
};
