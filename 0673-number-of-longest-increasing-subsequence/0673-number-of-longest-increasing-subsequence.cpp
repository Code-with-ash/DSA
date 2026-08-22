class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // longest increasing subsequence 
        int n =nums.size();
        int maxi = 1 ;
        vector<int> dp(n , 1);
        vector<int>cnt(n , 1);
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev = 0 ; prev < ind ; prev++){
                if(nums[prev]<nums[ind] && 1 + dp[prev] > dp[ind]){
                    dp[ind] = dp[prev] +1 ;
                    cnt[ind] = cnt[prev];
                }
                else if(nums[prev]<nums[ind] && dp[prev]+1 == dp[ind]){
                    cnt[ind] +=cnt[prev];
                } 
            }
                maxi = max(maxi , dp[ind]);
        }
        int counter = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(dp[i]==maxi) counter = counter + cnt[i];
        }
        return counter ; // this returns length of longest subsequnces 
    }
};