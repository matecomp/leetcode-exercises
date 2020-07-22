class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int idx, int x, int y) {  
        if (x < 0 || x >= board.size()) return false;
        if (y < 0 || y >= board[x].size()) return false;
        
        char target = word[idx];
        if (board[x][y] == target) {
            board[x][y] = '#';
            if (idx == word.size()-1) {
                return true;
            } else if (
                check(board, word, idx+1, x+1, y) ||
                check(board, word, idx+1, x-1, y) ||
                check(board, word, idx+1, x, y+1) ||
                check(board, word, idx+1, x, y-1)
            ) {
                return true;
            }

            board[x][y] = target;   
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (check(board, word, 0, i, j)) return true;
            }
        }
        
        return false;
    }
};