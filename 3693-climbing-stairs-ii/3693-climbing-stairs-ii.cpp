class Solution {
    int f(int i, int n, vector<int>& costs , vector<int>& dp) {
        if (i == n) {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int onestep = INT_MAX, twostep = INT_MAX, threestep = INT_MAX;
       if(i + 1 <= n)  onestep = costs[i] + 1 + f(i + 1, n, costs , dp);
        if(i + 2 <= n) twostep = costs[i+1] + 4 + f(i + 2, n, costs , dp);
        if(i + 3 <= n) threestep = costs[i+2] + 9 + f(i + 3, n, costs , dp);
        return dp[i] = min(onestep, min(twostep, threestep));
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        // from n+1 steps
        vector<int> dp(n , -1);
        return f(0, n, costs , dp );
    }
};