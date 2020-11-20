class Solution {
public:
    int pitagoras(float a, float b) {
        return a*a + b*b;
    }
    int dist(vector<int>& p1, vector<int>& p2) {
        int delta_0 = p1[0] - p2[0];
        int delta_1 = p1[1] - p2[1];
        return pitagoras(delta_0, delta_1);
    }
    
    bool isEqual(vector<int>& p1, vector<int>& p2) {
        return p1[0] == p2[0] && p1[1] == p2[1];
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (isEqual(p1,p2) || isEqual(p1,p3) || isEqual(p1,p4)) return false;
        
        vector<int> dists;
        dists.push_back(dist(p1, p2));
        dists.push_back(dist(p1, p3));
        dists.push_back(dist(p1, p4));
        
        dists.push_back(dist(p2, p3));
        dists.push_back(dist(p2, p4));
        
        dists.push_back(dist(p3, p4));
        sort(dists.begin(), dists.end());
        
        return (dists[0] == dists[1] && dists[5] == 2*dists[0]);
    }
};