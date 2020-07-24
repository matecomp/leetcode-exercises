class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int i=0; i<nums.size(); i++) {
            result ^= nums[i];
        }
        
        int pos = 0;
        
        while ((result & (1 << pos)) == 0) pos++;
        
        int num1 = 0;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] & (1 << pos)) num1 ^= nums[i];
        }
        
        int num2 = result ^ num1;
        
        vector<int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        
        return ans;
    }
};