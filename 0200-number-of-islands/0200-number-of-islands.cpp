class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
        int n = grid.size(), m = grid[0].size();
        visited[row][col] = 1;
        for(int i = 0; i < 4; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m
               && !visited[nr][nc] && grid[nr][nc]=='1')
                dfs(nr, nc, visited, grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> visited(r, vector<int>(c, 0));  // Bug 2 fixed

        int counter = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!visited[i][j] && grid[i][j]=='1'){  // Bug 3,4 fixed
                    dfs(i, j, visited, grid);
                    counter++;                           // Bug 6 fixed
                }
            }
        }
        return counter;
    }
};