class Solution {
private:
    int f(int i, int j, vector<int>& arr , vector<vector<int>>&dp) {
        if (i > j)
            return 0;
            if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            int ans = arr[j + 1] - arr[i - 1] + f(i, ind - 1, arr , dp) +
                      f(ind + 1, j, arr , dp);
            mini = min(ans, mini);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size() , vector<int>(cuts.size(), -1));
        return f(1, cuts.size() - 2, cuts , dp);
        }
    };