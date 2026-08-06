class Solution {
    // private:
    // int answer(int currrow , int currcol , vector<vector<int>>& grid ){
    //     if(currrow == 0 & currcol == 0 ) return grid[0][0];
    //     int up = INT_MAX ; int left = INT_MAX ;
    //     if(currrow > 0 ) up = grid[currrow][currcol] +answer(currrow -1 ,
    //     currcol , grid); if(currcol > 0 ) left = grid[currrow][currcol]+
    //     answer( currrow , currcol -1 , grid ); return min(up , left );
    // }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = grid[0][0];
                    continue;
                }
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)
                    up = grid[i][j] + prev[j];
                if (j > 0)
                    left = grid[i][j] + curr[j - 1];
                curr[j] = min(up, left);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};