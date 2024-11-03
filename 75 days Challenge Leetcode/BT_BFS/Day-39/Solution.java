/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */ 
import java.util.*;

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
     public List<Integer> rightSideView(TreeNode root) {
         List<Integer> result = new ArrayList<>();
         if (root == null) return result;
 
         Queue<TreeNode> queue = new LinkedList<>();
         queue.offer(root);
 
         while (!queue.isEmpty()) {
             int levelSize = queue.size();
             for (int i = 0; i < levelSize; i++) {
                 TreeNode node = queue.poll();
                 
                 // Add the last node of each level to the result
                 if (i == levelSize - 1) {
                     result.add(node.val);
                 }

                 // Enqueue left and right children
                 if (node.left != null) queue.offer(node.left);
                 if (node.right != null) queue.offer(node.right);
             }
         }
         return result;
     }
 }
