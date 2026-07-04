class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;

        // Step 1: push all 0s
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        // Step 2: BFS
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row      = q.front().first.first;
            int col      = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    ans[nr][nc] = distance + 1;
                    q.push({{nr,nc}, distance+1});
                }
            }
        }

        // Step 3: return
        return ans;
    }
};