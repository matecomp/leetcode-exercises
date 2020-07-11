class Solution {
public:
    void rec(vector<vector<int>>& ans, vector<int>& nums, int idx, vector<int> acc) {
        if (idx == nums.size()) {
            ans.push_back(acc);
            return;
        }
        
        rec(ans, nums, idx+1, acc);
        acc.push_back(nums[idx]);
        rec(ans, nums, idx+1, acc);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> acc;
        rec(ans, nums, 0, acc);
        return ans;
    }
};