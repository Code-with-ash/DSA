class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // dist[node][stops] = minimum cost to reach node using 'stops' edges
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});   // {cost, node, stops}

        while (!pq.empty()) {

            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst)
                return cost;

            if (stops == k + 1)
                continue;

            for (auto &[next, wt] : adj[node]) {

                int newCost = cost + wt;

                if (newCost < dist[next][stops + 1]) {
                    dist[next][stops + 1] = newCost;
                    pq.push({newCost, next, stops + 1});
                }
            }
        }

        return -1;
    }
};