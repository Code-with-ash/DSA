class Solution {
private:
    int countAtMost(vector<int>& nums, int k) {
        // When goal = 0, we call countAtMost(-1).
        // There cannot be any subarray with sum <= -1 in a binary array.
        if (k < 0) return 0;

        int l = 0;
        int sum = 0;
        int ans = 0;

        for (int r = 0; r < nums.size(); r++) {

            sum += nums[r];

            // GOOD:
            // You correctly realized we must keep shrinking
            // until the window becomes valid.
            while (sum > k) {
                sum -= nums[l];
                l++;
            }

           

            // MOST IMPORTANT INSIGHT:
            // Count all valid subarrays ending at r.
            ans += (r - l + 1);
        }

        return ans;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // exactly(goal)
        // =
        // atMost(goal)
        // -
        // atMost(goal-1)

        return countAtMost(nums, goal)
             - countAtMost(nums, goal - 1);
    }
};