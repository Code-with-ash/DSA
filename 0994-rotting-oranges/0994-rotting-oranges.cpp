class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));  // Bug 1 fixed

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    visited[i][j] = 2;
                }
                // mark fresh oranges in visited too
                if(grid[i][j] == 1) visited[i][j] = 1;
            }
        }

        int tm = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;    // Bug 2 fixed
            tm = max(tm, t);
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr < n && nr >= 0 && nc < m && nc >= 0){   // Bug 3 fixed
                    if(grid[nr][nc] == 1 && visited[nr][nc] != 2){
                        q.push({{nr, nc}, t+1});
                        visited[nr][nc] = 2;                   // Bug 4 fixed
                    }
                }
            }
        }

        // check if any fresh orange remains
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(visited[i][j] == 1) return -1;  // unreachable fresh orange

        return tm;
    }
};