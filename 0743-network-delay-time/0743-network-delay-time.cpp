class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++)
            adj[times[i][0]].push_back({times[i][1], times[i][2]});

        vector<int> timetaken(n+1, 1e9);  // Bug 1,4 fixed
        timetaken[k] = 0;

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;  // Bug 2 fixed
        pq.push({0, k});

        while(!pq.empty()){
            int time    = pq.top().first;   // Bug 3 fixed
            int current = pq.top().second;
            pq.pop();

            for(int i = 0; i < adj[current].size(); i++){
                int dest   = adj[current][i].first;
                int weight = adj[current][i].second;
                if(weight + time < timetaken[dest]){
                    timetaken[dest] = weight + time;
                    pq.push({timetaken[dest], dest});
                }
            }
        }

        int maxtime = 0;
        for(int i = 1; i <= n; i++){         // Bug 5 fixed
            if(timetaken[i] == 1e9) return -1;
            maxtime = max(maxtime, timetaken[i]);
        }
        return maxtime;
    }
};