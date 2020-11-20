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
    int bestDiff = 0;
    int computeDiff(TreeNode* node, pair<int,int> min_max) {
        if (!node) return 0;
        
        min_max.first = min(min_max.first, node->val);
        min_max.second = max(min_max.second, node->val);
        
        if (node->left == nullptr && node->right == nullptr) {
            return min_max.second - min_max.first;
        }
        
        int left = computeDiff(node->left, min_max);
        int right = computeDiff(node->right, min_max);
        
        
        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        int diff = computeDiff(root, {999999, -999999});
        return diff;
    }
};