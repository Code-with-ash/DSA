class Solution {
    int f(int i , int j , vector<int>& nums , vector<vector<int>>& dp){
        // base case 
        if(i > j ) return 0 ;
        int maxi = INT_MIN ;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind  = i ; ind<= j ; ind++){
            int cost  = nums[i-1] * nums[ind] * nums[j+1] + f(i , ind-1 , nums ,dp) + f(ind+1 , j , nums , dp);
            maxi = max(maxi , cost);
        }
        return dp[i][j] = maxi  ;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1 );
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+2 , vector<int>(nums.size()+2 , -1));
        return f(1, nums.size()-2, nums ,dp);
    }
};