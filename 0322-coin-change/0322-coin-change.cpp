class Solution {
    private :
    int answer(int ind , int target , vector<int>& coins , vector<vector<int>>& dp){
        if(ind == 0 ){ 
            if(target%coins[ind]== 0 ){
                // possible
                return target / coins[ind] ; 
            }else{
                // never possible 
                return 1e9;
            }
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake = 0 + answer(ind-1 , target , coins , dp);
        int take = INT_MAX ;
        if(coins[ind] <= target){
            take = 1 + answer(ind , target - coins[ind] , coins , dp );
        }
      return dp[ind][target] = min(take , nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1 , -1 ));
        int ans = answer(n-1 , amount , coins , dp) ;
        if(ans == 1e9) return -1 ;
        else return ans ;
    }
};