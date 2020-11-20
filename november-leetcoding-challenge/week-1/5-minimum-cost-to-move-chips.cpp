class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int sumA = 0;
        int sumB = 0;
        
        for (int i=0; i<position.size(); i++) {
            if (position[i]%2) sumB++;
            else sumA++;
        }

        return min(sumA, sumB);
    }
};