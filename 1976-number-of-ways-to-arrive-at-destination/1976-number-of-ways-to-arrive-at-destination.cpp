class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int src = 0;
        int dest = n - 1;

        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back(
                {roads[i][0], roads[i][2]}); // Bug 1 fixed
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        vector<long long> dist(n, 1e18); // Bug 3 fixed
        vector<long long> ways(n, 0);
        dist[src] = 0;
        ways[src] = 1;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();

            for (auto& [next, weight] : adj[node]) {
                if (weight + distance < dist[next]) {
                    dist[next] = weight + distance;
                    ways[next] = ways[node];
                    pq.push({dist[next], next});
                } else if (weight + distance == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % MOD; // Bug 2 fixed
                }
            }
        }
        return ways[dest] % MOD;
    }
};