class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 0) return cells;
        
        int value = 0;
        for (int i=0; i<cells.size(); i++) {
            value <<= 1;
            value += cells[i];
        }
        
        N = N%14;
        if (N == 0) N = 14;
        for (int i=0; i<N; i++) {
            value = ~ ((value << 1) ^ (value >> 1));
            if (value < 0) value &= 127;
            if (value & 1) value--;
        }
    
        for (int i=0; i<cells.size(); i++) {
            cells[i] = (value & 1 << (cells.size() - i - 1)) > 0;
        }

        return cells;
    }
};