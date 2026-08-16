class Solution {
private:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        // base case
        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (i < 0 && j >= 0) {
            for (int ind = 0; ind <= j; ind++) {
                if (p[ind] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        } else if (p[j] == '*') {
            bool stay = f(i - 1, j, s, p, dp);
            bool eliminate = f(i, j - 1, s, p, dp);
            return dp[i][j] = eliminate || stay;
        }
        return dp[i][j] = false ;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n - 1, m - 1, s, p, dp);
    }
};