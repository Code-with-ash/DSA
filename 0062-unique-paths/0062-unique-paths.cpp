class Solution {
private:
    int paths(int curr_row, int curr_col, int row, int col, vector<vector<int>>& dp){
        if(curr_row == 0 && curr_col == 0){
            return 1;
        }
        if(dp[curr_row][curr_col] != -1){
            return dp[curr_row][curr_col];
        }
        int up = 0, left = 0;
        if(curr_row > 0){
            up = paths(curr_row - 1, curr_col, row, col, dp);
        }
        if(curr_col > 0){
            left = paths(curr_row, curr_col - 1, row, col, dp);
        }
        return dp[curr_row][curr_col] = up + left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m-1, n-1, m, n, dp);
    }
};