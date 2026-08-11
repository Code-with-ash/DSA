class Solution {
    // private :
    // int answer(int ind , int target , vector<int>& coins , vector<vector<int>>& dp){
    //     if(ind == 0 ){ 
    //         if(target%coins[ind]== 0 ){
    //             // possible
    //             return target / coins[ind] ; 
    //         }else{
    //             // never possible 
    //             return 1e9;
    //         }
    //     }
    //     if(dp[ind][target]!=-1) return dp[ind][target];
    //     int nottake = 0 + answer(ind-1 , target , coins , dp);
    //     int take = INT_MAX ;
    //     if(coins[ind] <= target){
    //         take = 1 + answer(ind , target - coins[ind] , coins , dp );
    //     }
    //   return dp[ind][target] = min(take , nottake);
    // }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1 , -1 ));
        for(int i = 0 ; i <= amount ; i++){
             if( i % coins[0] == 0 ){
                // possible
                dp[0][i] = i / coins[0] ; 
            }else{
                // never possible 
                dp[0][i] = 1e9;
            }
        }

        for(int ind = 1 ; ind < n ; ind++ ){
            for(int target = 0 ; target <= amount ; target++){
                int nottake = dp[ind-1][target];
                int take = INT_MAX ;
                if(coins[ind]<= target){
                    take = 1 + dp[ind][target - coins[ind]];
                }
                dp[ind][target] = min(take , nottake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans == 1e9 ) return -1 ;
        else return ans ;
    }
};