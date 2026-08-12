class Solution {
    // private:
    //     int answer(int ind, int target, vector<int>& nums ,
    //     vector<vector<int>>& dp){
    //         if(ind == 0){
    //             if(target == 0 && nums[0] == 0) return 2; // both +0 and -0
    //             count separately if(target == 0 || target == nums[0]) return
    //             1; return 0;
    //         }
    //         if(dp[ind][target]!= -1) return dp[ind][target];
    //         int nottake = answer(ind-1, target, nums , dp);
    //         int take = 0;
    //         if(nums[ind] <= target){
    //             take = answer(ind-1, target - nums[ind], nums , dp );
    //         }
    //         return dp[ind][target] = take + nottake;
    //     }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum)
            return 0;
        if ((totalSum - target) % 2 != 0)
            return 0;
        int P = (totalSum - target) / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(P + 1, -1));
        for (int i = 0; i <= P; i++) {
            dp[0][i] = 0;
        }
        if (nums[0] == 0)
            dp[0][0] = 2;
        else {
            dp[0][0] = 1;
            if (nums[0] <= P)
                dp[0][nums[0]] = 1;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int t = 0; t <= P; t++) {
                int notake = dp[i - 1][t];
                int take = 0;
                if (nums[i] <= t) {
                    take = dp[i - 1][t - nums[i]];
                }
                dp[i][t] = take + notake;
            }
        }
        return dp[nums.size() - 1][P];
    }
};