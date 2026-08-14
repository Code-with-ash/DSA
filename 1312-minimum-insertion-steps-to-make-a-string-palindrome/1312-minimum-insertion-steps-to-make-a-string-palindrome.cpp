class Solution {
public:
    int minInsertions(string s) {
        string rev = s;
        int n = s.size();
        reverse(s.begin() , s.end());

        // vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        vector<int> prev(n+1 , 0);
        vector<int> curr(n+1 , 0);
        for(int i = 1 ; i <=n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(s[i-1]==rev[j-1]){
                    // 0 -> 1 
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j] , curr[j-1]);
                }
            }
            prev = curr ;
        }
        return n - prev[n];
    }
};