class Solution {
public:
    // Helper function to find the maximum value in the left subtree
    int findmax(TreeNode* root) {
        // Keep going right until you reach the largest node
        if (!root->right) return root->val;
        return findmax(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {       
        if (!root) return nullptr;  
        
        if (key < root->val) {
            // Key is smaller, so we search in the left subtree
            root->left = deleteNode(root->left, key); 
        } else if (key > root->val) {
            // Key is larger, so we search in the right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // Node with the key found
            if (!root->left) {
                // Case 1: Node has only right child or no child
                TreeNode* temp = root->right;
                delete root;  // Free the current node
                return temp;  // Return the right subtree
            } else if (!root->right) {
                // Case 2: Node has only left child
                TreeNode* temp = root->left;
                delete root;  // Free the current node
                return temp;  // Return the left subtree
            } else {
                // Case 3: Node has both children
                int maxLeft = findmax(root->left);  // Find max in left subtree
                root->val = maxLeft;                // Replace value with max
                // Recursively delete the max node from the left subtree
                root->left = deleteNode(root->left, maxLeft);
            }
        }
        return root;  
    }
};