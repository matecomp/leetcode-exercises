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
    
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int result = 0;
        while(!q.empty()) {
            int count = q.size();
            int begin = 0;
            int end = 0;
            
            bool first = true;
            int shift = 0;
            
            int offset = 0;
            for (int i=0; i<count; i++) {
                TreeNode* node = q.front().first;
                int idx = q.front().second;
                
                if (i == 0) begin = idx;
                if (i == count-1) end = idx;
                
                if (node->left) {
                    int temp = idx<<1;
                    if (first) offset = temp;
                    first = false;
                    
                    temp -= offset;
                    q.push({node->left, temp});
                }
                
                if (node->right) {
                    int temp = idx<<1;
                    if (first) offset = temp;
                    first = false;
                    
                    temp -= offset;
                    q.push({node->right, temp + 1});
                }
                

                
                q.pop();
            }
            
            result = max(result, end - begin + 1);
        }
        
        return result;
    }
};