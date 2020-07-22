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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<TreeNode*> elements;
        elements.push(root);
        
        bool zag = false;
        while (!elements.empty()) {
            int level_width = elements.size();
            
            vector<int> nodes;
            for (int i=0; i<level_width; i++) {
                TreeNode* cur_node = elements.front();
                elements.pop();
                
                int node_value = cur_node->val;
                nodes.push_back(node_value);
                
                if (cur_node->left) elements.push(cur_node->left);
                if (cur_node->right) elements.push(cur_node->right);
            }
            if (zag) reverse(nodes.begin(), nodes.end());
            
            ans.push_back(nodes);
            zag = !zag;
        }
        
        return ans;
    }
};