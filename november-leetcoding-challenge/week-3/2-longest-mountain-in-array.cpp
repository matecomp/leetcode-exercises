class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i = 0, j = -1,
            k = -1, p = 0,
            d = 0, n = 0;
    
        if (A.size() < 3) {
            return 0;
        }
    
        for (i = 0; i < A.size() - 1; i++) {
            if (A[i + 1] > A[i]) {
                if (k != -1) {
                    k = -1;
                    j = -1;
                }
                if (j == -1) {
                    j = i;
                }
            }
            else {
                if (A[i + 1] < A[i]) {
                    if (j != -1) {
                        k = i + 1;
                    }
                    if (k != -1 && j != -1) {
                        if (d < k - j + 1) {
                            d = k - j + 1;
                        }
                    }
                }
                else {
                    k = -1;
                    j = -1;
                }
            }
        }
    
        if (k != -1 && j != -1) {
            if (d < k - j + 1) {
                d = k - j + 1;
            }
        }
        return d;
    }
};