class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int maxdiff = pq.top().first;
            int row     = pq.top().second.first;
            int col     = pq.top().second.second;
            pq.pop();

            // reached destination
            if(row == n-1 && col == m-1) return maxdiff;

            // prune — already found better path to this cell
            if(maxdiff > dist[row][col]) continue;

            for(int i = 0; i < 4; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newdiff = max(maxdiff, abs(heights[nr][nc]-heights[row][col]));
                    if(newdiff < dist[nr][nc]){
                        dist[nr][nc] = newdiff;
                        pq.push({newdiff, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};