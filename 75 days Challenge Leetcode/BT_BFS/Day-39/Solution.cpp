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

#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) 
            return result;

        std::queue<TreeNode*> temp;
        temp.push(root);

        while (!temp.empty()) {
            int levelSize = temp.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = temp.front();
                temp.pop();

                // Add the last node of each level to the result
                if (i == levelSize - 1)
                    result.push_back(node->val);

                // Enqueue left and right children
                if (node->left) 
                    temp.push(node->left);
                if (node->right) 
                    temp.push(node->right);
            }
        }
        return result;
    }
};
