class Solution {
private:
    bool ispalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    // int f(int i, string& s, int n, vector<int>& dp) {
    //     if (i == n)
    //         return 0;
    //     int ans = INT_MAX;
    //     if (dp[i] != -1)
    //         return dp[i];
    //     for (int j = i; j < n; j++) {
    //         if (ispalindrome(i, j, s)) {
    //             int cuts = 1 + f(j + 1, s, n, dp);
    //             ans = min(ans, cuts);
    //         }
    //     }
    //     return dp[i] = ans;
    // }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
        int ans = INT_MAX;
            for(int j = i; j < n; j++) {
                if (ispalindrome(i, j, s)) {
                    int cuts = 1 + dp[j + 1] ;
                    ans = min(ans, cuts);
                }
            }
            dp[i] = ans;
        }
        return dp[0]-1;
    }
};