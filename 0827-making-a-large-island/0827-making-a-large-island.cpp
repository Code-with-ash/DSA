class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionbysize(int u, int v) {
        int up_u = findUpar(u);
        int up_v = findUpar(v);
        if (up_u == up_v)
            return;
        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        } else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        DisjointSet ds(rows * cols);
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int nr = i + delrow[k];
                        int nc = j + delcol[k];

                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                            grid[nr][nc] == 1) {
                            ds.unionbysize(i * cols + j, nr * cols + nc);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    set<int> s;                        
                    for (int k = 0; k < 4; k++) {
                        int nr = i + delrow[k];
                        int nc = j + delcol[k];
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {   
                            s.insert(ds.findUpar(nr * cols + nc));
                        }
                    }
                    int total = 0;
                    for (auto it : s) {
                        total += ds.size[it];           
                    }
                    total += 1;
                    ans = max(ans, total);
                }
            }
        }
        if(ans == 0) return rows*cols;
        return ans;
    }
};