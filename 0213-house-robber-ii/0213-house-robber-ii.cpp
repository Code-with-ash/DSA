class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0] ;

        vector<int> dp(n);
        // either we start from house 1 to n-1 or house 2 to n
        dp[0] = nums[0];
        
        // not taking last element 
        for(int i = 1 ; i < n-1 ; i++){
        int pick = nums[i] ;
        if(i>1){
            pick = pick + dp[i-2];
        }
        int dontpick = dp[i-1];
            dp[i] = max(pick,dontpick);
        }
       int ans1 = dp[n-2];


       fill(dp.begin(), dp.end(), 0);

       // now not taking 1st element 
       dp[1] = nums[1];
       for(int i = 2 ; i < n ; i++){
        int pick = nums[i] + dp[i-2];
        int notpick = dp[i-1];
        dp[i] = max(pick , notpick);
       }
       int ans2= dp[n-1];
       return max(ans1 , ans2);

    }
};