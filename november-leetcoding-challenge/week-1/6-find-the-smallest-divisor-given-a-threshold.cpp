class Solution {
public:
    long long int computeDivision(vector<int>& nums, int value) {
        long long int ans = 0;
        for (int i=0; i<nums.size(); i++) ans += ceil((1.0 * nums[i]) / value);
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int count = 1;
        while (computeDivision(nums, count) > threshold) {
            count*=2;
        }
        
        int left = count/2;
        int right = count;
        
        while (left < right-1) {
            int middle = (left+right)/2;
            if (computeDivision(nums, middle) <= threshold) {
                right = middle;
            } else {
                left = middle;
            }
        }
        return right;
    }
};