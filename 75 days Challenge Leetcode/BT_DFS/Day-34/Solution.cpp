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
    // Helper function to collect all leaf nodes of a tree
    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) return;  // Base case: if the node is null, return
        
        // Check if the current node is a leaf
        if (!root->left && !root->right) { 
            leaves.push_back(root->val);  // Add leaf value to the vector
            return;
        }

        // Recursively gather leaves from left and right subtrees
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
    
    // Main function to check if two trees are leaf-similar
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);  // Collect leaves from the first tree
        getLeaves(root2, leaves2);  // Collect leaves from the second tree
        return leaves1 == leaves2;  // Check if the leaf sequences are identical
    }
};
