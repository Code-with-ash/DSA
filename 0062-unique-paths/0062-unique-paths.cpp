class Solution {
private:
    // int paths(int curr_row, int curr_col, int row, int col, vector<vector<int>>& dp){
    //     if(curr_row == 0 && curr_col == 0){
    //         return 1;
    //     }
    //     if(dp[curr_row][curr_col] != -1){
    //         return dp[curr_row][curr_col];
    //     }
    //     int up = 0, left = 0;
    //     if(curr_row > 0){
    //         up = paths(curr_row - 1, curr_col, row, col, dp);
    //     }
    //     if(curr_col > 0){
    //         left = paths(curr_row, curr_col - 1, row, col, dp);
    //     }
    //     return dp[curr_row][curr_col] = up + left;
    // }
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n , 0);
        for(int i = 0 ; i < m ; i++){
                vector<int> curr (n , 0 );
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j ==0) curr[j] = 1 ;
                else{
                    // curr row = i , curr col = j 
                    int up = 0 ; int left = 0 ;
                       if(i>0) up = prev[j];
                       if(j>0) left = curr[j-1];
                    curr[j] = up + left ;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};