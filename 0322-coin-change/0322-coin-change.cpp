class Solution {
    int f(int ind, vector<int>& coins, int target ,vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target % coins[0] == 0)
                return target / coins[0];
            return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int dontPick = f(ind - 1, coins, target , dp);

        int pick = 1e9;
        if (coins[ind] <= target)
            pick = 1 + f(ind, coins, target - coins[ind] , dp);

        return dp[ind][target] = min(pick, dontPick);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(coins.size() - 1, coins, amount , dp);
        return ans >= 1e9 ? -1 : ans;
    }
};