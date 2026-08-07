class Solution {
// private:
//     int answer(int row, int col, vector<vector<int>>& triangle, int rows,
//                vector<vector<int>>& dp) {
//         if (row == rows)
//             return triangle[rows][col];
//         if (dp[row][col] != -1)
//             return dp[row][col];
//         int down =
//             triangle[row][col] + answer(row + 1, col, triangle, rows, dp);
//         int diagonal =
//             triangle[row][col] + answer(row + 1, col + 1, triangle, rows, dp);
//         return dp[row][col] = min(down, diagonal);
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();

        vector<vector<int>> dp(rows, vector<int>(rows, 0));

        for(int i = 0; i < rows ; i++) {
            dp[rows - 1][i] = triangle[rows - 1][i];
        }

        for(int i = rows -2 ; i >= 0; i--) {
            for(int j = i ; j >= 0 ; j--){
                int down =  triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j]  + dp[i+1][j+1];
                dp[i][j] = min(down , diagonal);
            }
        }
        return dp[0][0];
    }
};