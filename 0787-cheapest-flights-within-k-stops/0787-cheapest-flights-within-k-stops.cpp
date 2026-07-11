class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src, 0}});   // {stops, {node, cost}}

        while (!q.empty()) {

            auto [stops, temp] = q.front();
            auto [node, cost] = temp;
            q.pop();

            if (stops > k)
                continue;

            for (auto &[next, wt] : adj[node]) {

                if (cost + wt < dist[next]) {
                    dist[next] = cost + wt;
                    q.push({stops + 1, {next, cost + wt}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};