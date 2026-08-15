class Solution {
private:
    int f(int i, int j, string& word1, string& word2 , vector<vector<int>>& dp) {
        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if (word1[i] == word2[j]) {
            return dp[i][j] = f(i - 1, j - 1, word1, word2 , dp);
        } else {
            // either we can insert , delete or update
            // insertion
            int insert =  1 + f(i, j - 1, word1, word2 , dp);
            int replace =  1 + f(i - 1, j - 1, word1, word2 , dp);
            int deleted =  1 + f(i - 1, j, word1, word2 , dp);
            return dp[i][j] = min(insert, min(replace, deleted));
        }
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        return f(n, m, word1, word2 , dp);
    }
};