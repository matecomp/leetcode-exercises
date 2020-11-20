class Solution {
public:
    void permute(vector<vector<int>>& acc, vector<int>& nums, vector<int>& vis, vector<int>& seq) {
        if (seq.size() == nums.size()) {
            acc.push_back(seq);
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (vis[i] == 0) {
                vector<int> temp = seq;
                temp.push_back(nums[i]);
                vis[i] = 1;
                permute(acc, nums, vis, temp);
                vis[i] = 0;
            }
        }
        
        return;
    }
    vector<vector<int>> getUnique(vector<vector<int>> acc) {
        map<vector<int>, int> vis; 
        vector<vector<int>> unique;
        
        for (int i=0; i<acc.size(); i++) {
            if (vis[acc[i]]) continue;
            vis[acc[i]] = 1;
            unique.push_back(acc[i]);
        }
        
        return unique;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vis(nums.size(), 0);
        vector<vector<int>> acc;
        vector<int> empty;
        permute(acc, nums, vis, empty);
        
        return getUnique(acc);
    }
};