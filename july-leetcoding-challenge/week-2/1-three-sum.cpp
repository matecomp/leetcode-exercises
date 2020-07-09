class Solution {
public:
    bool findSum(vector<int>& nums, int left, int right, vector<vector<int>>& acc) {
        if (left+1 >= right) return false;
        
        int target = -(nums[left] + nums[right]);

        if (binary_search(nums.begin()+left+1, nums.begin()+right, target)) {
            acc.push_back(vector<int>{ nums[left], target, nums[right] });
            return true;
        }
        
        return false;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        
        vector<vector<int>> acc;
        while (left < right) {            
            int next_left = left+1;    
            while(next_left < nums.size()-1 && nums[next_left-1] == nums[next_left]) next_left++;
            
            int next_right = right;
            while(left < next_right) {
                findSum(nums, left, next_right, acc);
                next_right--;
                while(next_right > 0 && nums[next_right+1] == nums[next_right]) next_right--;
            }
            
            left = next_left;
        }
        
        return acc;
    }
};