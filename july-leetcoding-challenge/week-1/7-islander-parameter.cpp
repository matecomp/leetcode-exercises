class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        stack<pair<int,int> > coords;
        
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j]) {
                    coords.push({i,j});
                    grid[i][j] = 2;
                    break;
                }
            }
            
            if (!coords.empty()) break;
        }
        
        int perimeter = 0;
        pair<int,int> coord;
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!coords.empty()) {
            coord = coords.top();
            coords.pop();

            for (int i=0; i<4; i++) {
                int row = coord.first + dy[i];
                int col = coord.second + dx[i];

                if ((row >= 0 && row < grid.size()) && (col >= 0 && col < grid[row].size())) {
                    if(grid[row][col] == 1) {
                        grid[row][col] = 2;
                        coords.push({row,col});
                    }
                    
                    if(grid[row][col] == 0) {
                        perimeter++;
                    }
                } else {
                    perimeter++;
                }
            }
        }
        
        return perimeter;
    }
};