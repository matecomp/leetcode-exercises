class Solution {
public:
    int invert(int num) {
        if (num) return 0;
        
        return 1;
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i=0; i<A.size(); i++) {
            int cols = A[i].size();
            for (int j=0; j*2<cols; j++) {
                int temp = A[i][j];
                A[i][j] = A[i][cols-1-j];
                A[i][cols-1-j] = temp;
            }
            
            for (int j=0; j<cols; j++) A[i][j] = invert(A[i][j]);
        }
        
        return A;
    }
};