class Solution {
    // private:
    //     int f(int i, int j, string& word1, string& word2 ,
    //     vector<vector<int>>& dp) {
    //         if (i < 0) {
    //             return j + 1;
    //         }
    //         if (j < 0) {
    //             return i + 1;
    //         }
    //         if(dp[i][j]!=-1) return dp[i][j];
    //         if (word1[i] == word2[j]) {
    //             return dp[i][j] = f(i - 1, j - 1, word1, word2 , dp);
    //         } else {
    //             // either we can insert , delete or update
    //             // insertion
    //             int insert =  1 + f(i, j - 1, word1, word2 , dp);
    //             int replace =  1 + f(i - 1, j - 1, word1, word2 , dp);
    //             int deleted =  1 + f(i - 1, j, word1, word2 , dp);
    //             return dp[i][j] = min(insert, min(replace, deleted));
    //         }
    //     }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            // string 2 got exhausted
            dp[i][0] = i ;
        }
        for (int j = 1; j <= m; j++) {
            // string1 got exhausted
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insert = 1 + dp[i][j - 1];
                    int replace = 1 + dp[i - 1][j - 1];
                    int deleted = 1 + dp[i - 1][j];
                    dp[i][j] = min(insert, min(replace, deleted));
                }
            }
        }
        return dp[n][m];
    }
};