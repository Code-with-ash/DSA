class Solution {
private:
    bool compare(string a, string b) {
        if (a.size() != b.size() + 1) return false;
        int i = 0;
        int j = 0;
        while (i < a.size()){
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if(i == a.size() && j == b.size())return true; // both on end 
        return false ;
    }
static bool comp(string& a , string& b){
    return a.size() < b.size();
}
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 1;
        vector<int> dp(n, 1);
        sort(words.begin() , words.end() , comp);
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (compare(words[ind], words[prev]) &&
                    dp[prev] + 1 > dp[ind]) {
                    dp[ind] = 1 + dp[prev];
                }
                if (dp[ind] > maxi) {
                    maxi = max(maxi, dp[ind]);
                }
            }
        }
        return maxi;
    }
};