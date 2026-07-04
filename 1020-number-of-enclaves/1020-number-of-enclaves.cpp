class Solution {
    void dfs(int row , int col , vector<vector<int>>& visited , vector<vector<int>>& grid){
        visited[row][col]=1;
        vector<int> delrow = {-1 , 0 , 1 ,0};
        vector<int> delcol = {0 , 1 , 0 ,-1};
        for(int i = 0 ; i<4 ; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr>=0 && nc>=0 && nr < grid.size() && nc < grid[0].size() && !visited[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc , visited , grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1 && !visited[0][i]) {
                dfs(0, i, visited, grid);
            }
            if (grid[m - 1][i] == 1 && !visited[m - 1][i]) {
                dfs(m-1, i, visited, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) {
                dfs(i , 0, visited, grid);
            }
            if (grid[i][n - 1] == 1 && !visited[i][n - 1]) {
                dfs(i , n-1 , visited, grid);
            }
        }
        int count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};