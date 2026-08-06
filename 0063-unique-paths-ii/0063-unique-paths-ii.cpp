class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
       dp[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(i == 0 && j == 0 ) continue ;
                int up = 0 ; int left = 0 ;
                if(i>0 && obstacleGrid[i][j]!=1 ) up = dp[i-1][j];
                if(j>0 && obstacleGrid[i][j]!=1 ) left = dp[i][j-1];
                dp[i][j] = up + left ;
            }
        }
        return dp[row-1][col-1];
    }
};