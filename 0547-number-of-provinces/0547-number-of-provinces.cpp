class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            if (visited[adj[node][i]] != 1)
                dfs(adj[node][i], adj, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j] == 1 && i != j)
                    adj[i].push_back(j);

        vector<int> visited(n + 1, 0);
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] != 1) {
                counter++;
                dfs(i, adj, visited);
            }
        }
        return counter;
    }
};