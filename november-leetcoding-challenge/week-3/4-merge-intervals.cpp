class Solution {
public:
    
    bool isOverlap(vector<int> a, vector<int> b) {
        bool check1 = (a[0] <= b[0] && a[1] >= b[0]) || (a[0] <= b[1] && a[1] >= b[1]);
        bool check2 = (b[0] <= a[0] && b[1] >= a[0]) || (b[0] <= a[1] && b[1] >= a[1]);
        return check1 || check2;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        
        sort(intervals.begin(), intervals.end());
        
        for (int i=0; i<intervals.size(); i++) {
            bool isMerged = false;
            for (int j=0; j<merged.size(); j++) {
                if (isOverlap(intervals[i], merged[j])) {
                    merged[j][0] = min(merged[j][0], intervals[i][0]);
                    merged[j][1] = max(merged[j][1], intervals[i][1]);
                    isMerged = true;
                }
            }
            
            if (!isMerged) merged.push_back(intervals[i]);
        }
        
        return merged;
    }
};