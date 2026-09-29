class Solution {
    int f(int i , int j , int m , int n , string& text1 , string& text2 , vector<vector<int>>& dp){
        if(i==m || j == n){
            return 0 ;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j] = 1+f(i+1,j+1 , m, n , text1 , text2 , dp);
        }
        else{
            return dp[i][j] = max(f(i+1,j,m,n,text1,text2 , dp) , f(i,j+1 , m ,n , text1 , text2 , dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n , -1));
        return f(0,0,m,n,text1 , text2,dp);
    }
};