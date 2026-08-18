class Solution {
      private:
    int f(int ind , int buy , int cap ,vector<int>& prices ,int n , vector<vector<vector<int>>>& dp){
        if(ind == n || cap == 0 ) return 0 ;
        int profit = 0 ;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            int bought = - prices[ind] + f(ind+1 , 0 , cap , prices , n , dp );
            int notbuy = f(ind+1 , 1 , cap , prices , n, dp);
            profit = max(bought , notbuy);
        }else{
            int sell = prices[ind] + f(ind+1 , 1 , cap-1 ,prices , n, dp);
            int dontsell = f(ind+1 , 0 , cap,prices , n , dp);
            profit = max(sell , dontsell);
        }
       return dp[ind][buy][cap] = profit ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0 , 1 , k , prices , n , dp);
    }
};