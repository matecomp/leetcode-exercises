class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> p;
        
        
        for (int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        for (unordered_map<int,int>::iterator it=freq.begin(); it!=freq.end(); ++it) {
            p.push({it->second,it->first});
        }
        
        vector<int> result;
        
        while (k) {
            result.push_back(p.top().second);
            p.pop();
            k--;
        }
        
        return result;
    }
};