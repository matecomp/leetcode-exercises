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
    TreeNode* rec(vector<int> inorder, map<int,int>& idxs) {
        if (inorder.size() == 0) return nullptr;
        
        int max_idx = 0, value;
        
        for (int i=0; i<inorder.size(); i++) {
            if (max_idx <= idxs[inorder[i]] - 1) {
                max_idx = idxs[inorder[i]] - 1;
                value = inorder[i];
            }
        }
        

        TreeNode* root = new TreeNode(value);
        
        vector<int> inleft, inright;
        
        int left = 0, right = inorder.size() - 1;
        
        while (left != right) {
            if (inorder[left] != value) {
                inleft.push_back(inorder[left]);
                left++;
            }
            
            if (inorder[right] != value) {
                inright.push_back(inorder[right]);
                right--;
            }
        }
        
        reverse(inright.begin(), inright.end());
        
        root->left = rec(inleft, idxs);
        root->right = rec(inright, idxs);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int,int> idxs;
        
        for (int i=0; i<postorder.size(); i++) idxs[postorder[i]] = i+1;
        
        return rec(inorder, idxs);
    }
};