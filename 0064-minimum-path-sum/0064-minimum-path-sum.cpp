class Solution {
    // private:
    // int answer(int currrow , int currcol , vector<vector<int>>& grid ){
    //     if(currrow == 0 & currcol == 0 ) return grid[0][0];
    //     int up = INT_MAX ; int left = INT_MAX ; 
    //     if(currrow > 0 ) up = grid[currrow][currcol] +answer(currrow -1 , currcol , grid);
    //     if(currcol > 0 ) left = grid[currrow][currcol]+ answer( currrow , currcol -1 , grid );
    //     return min(up , left );
    // }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        dp[0][0] = grid[0][0];
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0  ) continue ;
                int up = INT_MAX ; int left = INT_MAX ; 
                if(i > 0) up = grid[i][j]+ dp[i-1][j];
                if(j > 0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up , left);
            }
        }
        return dp[m-1][n-1];
    }
};