class Solution {
    // private:
    //     bool answer(int index, int target, vector<int>& nums,
    //                 vector<vector<int>>& dp) {
    //         if (target == 0)
    //             return true;
    //         if (index == 0)
    //             return (nums[0] == target);
    //         if (dp[index][target] != -1)
    //             return dp[index][target];
    //         bool nottake = answer(index - 1, target, nums, dp);
    //         bool take = false;
    //         if (target >= nums[index]) {
    //             take = answer(index - 1, target - nums[index], nums, dp);
    //         }
    //         return dp[index][target] = take | nottake;
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums)
            sum += x;
        if (sum % 2)
            return false;
        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= target)
            dp[0][nums[0]] = true;
        for (int index = 1; index < n; index++) {

            for (int j = 1; j <= target; j++) {

                bool nottake = dp[index - 1][j];

                bool take = false;
                if (j >= nums[index])
                    take = dp[index - 1][j - nums[index]];
                    
                dp[index][j] = take || nottake;
            }
        }

        return dp[n - 1][target];
    }
};