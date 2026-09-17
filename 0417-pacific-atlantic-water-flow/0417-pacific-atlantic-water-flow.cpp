class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>>& visited) {
        int row = heights.size(), col = heights[0].size();
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < row && nc < col 
                    && !visited[nr][nc] 
                    && heights[nr][nc] >= heights[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));

        queue<pair<int,int>> pq, aq;

        // Seed Pacific: top row + left column
        for (int j = 0; j < col; j++) { pacific[0][j] = true; pq.push({0, j}); }
        for (int i = 0; i < row; i++) { pacific[i][0] = true; pq.push({i, 0}); }

        // Seed Atlantic: bottom row + right column
        for (int j = 0; j < col; j++) { atlantic[row-1][j] = true; aq.push({row-1, j}); }
        for (int i = 0; i < row; i++) { atlantic[i][col-1] = true; aq.push({i, col-1}); }

        bfs(heights, pq, pacific);
        bfs(heights, aq, atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});

        return result;
    }
};