class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return 0; 

        queue<TreeNode*> temp;         // Queue to traverse levels of the tree
        temp.push(root);               // Start BFS traversal with the root node

        int level = 1;                 // Tracks the current level
        int maxLevel = 1;              // Tracks the level with the maximum sum
        int maxSum = root->val;        // Initialize maxSum with the root node's value

        while (!temp.empty()) {
            int levelSize = temp.size(); // Number of nodes at the current level
            int levelSum = 0;            // Sum of values at the current level
            
            // Traverse all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = temp.front();
                temp.pop();
                levelSum += node->val;   // Add the node's value to levelSum
                
                // Add child nodes for the next level
                if (node->left) temp.push(node->left);
                if (node->right) temp.push(node->right);
            }
            
            // Check if current level has a greater sum than maxSum
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = level;
            }
            
            level++; 
        }
        
        return maxLevel; // Return the level with the maximum sum
    }
};