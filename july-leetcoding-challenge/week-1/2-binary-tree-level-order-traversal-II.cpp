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
    vector<vector<int>> parseTree(TreeNode* node) {
        vector<vector<int>> tree;

        if (node->left == nullptr && node->right == nullptr) {
            tree.push_back(vector<int>(1, node->val));
            return tree;
        }
        
        vector<vector<int>> left_tree, right_tree;
        
        if (node->left) {
            left_tree = parseTree(node->left);
        }
        
        if (node->right) {
            right_tree = parseTree(node->right);
        }
        
        int level = max(left_tree.size(), right_tree.size());
        
        for (int i=0; i<level; i++) {
            
            vector<int> temp;
    
            if (left_tree.size() > i) {
                int idx = left_tree.size() - 1 - i;
                temp.reserve(left_tree[idx].size());
                temp.insert( temp.end(), left_tree[idx].begin(), left_tree[idx].end() );
            }
            
            if (right_tree.size() > i) {
                int idx = right_tree.size() - 1 - i;
                temp.reserve(right_tree[idx].size());
                temp.insert( temp.end(), right_tree[idx].begin(), right_tree[idx].end() );
            }
            
            tree.push_back(temp);
            
        }
        
        reverse(tree.begin(), tree.end());
        
        tree.push_back(vector<int>(1, node->val));
        return tree;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr)  return vector<vector<int>>();
        vector<vector<int>> tree_nodes = parseTree(root);
        return tree_nodes;
    }
};