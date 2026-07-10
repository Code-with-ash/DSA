class Solution {
    int delrow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int delcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int,int>>> q;

        q.push({1, {0, 0}});    // Bug 4 fixed
        dist[0][0] = 1;

        while(!q.empty()){
            int distance = q.front().first;
            int row      = q.front().second.first;
            int col      = q.front().second.second;
            q.pop();               // Bug 2 fixed

            for(int i = 0; i < 8; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n    // Bug 3 fixed
                   && grid[nr][nc]==0
                   && distance+1 < dist[nr][nc]){
                    dist[nr][nc] = distance + 1;
                    q.push({distance+1, {nr, nc}});
                }
            }
        }
        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];  // Bug 5 fixed
    }
};