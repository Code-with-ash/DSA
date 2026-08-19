class Solution {
    int f(int ind, int prevIndex, vector<int>& nums, vector<vector<int>>& dp , int n) {
        if (ind == n)
            return 0;

        if (dp[ind][prevIndex + 1] != -1)
            return dp[ind][prevIndex + 1];

        int take = 0;

        if (prevIndex == -1 || nums[ind] > nums[prevIndex])
            take = 1 + f(ind + 1, ind, nums, dp , n);

        int dontTake = f(ind + 1, prevIndex, nums, dp , n);

        return dp[ind][prevIndex + 1] = max(take, dontTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, -1, nums, dp , n);
    }
};