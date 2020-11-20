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
    int findTilt(TreeNode* root) {
        int total = 0;
        helper(root, total);
        return total;
    }
  
    int helper(TreeNode* root, int total) {
        if (root == nullptr) {
            return 0;
        }
        int left = helper(root->left, total);
        int right = helper(root->right, total);
        total += abs(left - right);
        return left + right + root->val;
    }
};