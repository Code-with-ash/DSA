class Solution {
    int f(int ind , vector<int>& cost , int n , vector<int>&dp){
        if(ind>=n) return 0 ;
        if(dp[ind]!=-1) return dp[ind];
        int onestep = cost[ind] + f(ind+1 , cost , n , dp);
        int twostep = cost[ind] + f(ind+2 , cost , n , dp);
        return dp[ind] = min(onestep , twostep);

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        int zero = f(0 , cost ,n ,dp );
        int first = f(1 , cost , n , dp);
        return min(zero , first);
    }
};