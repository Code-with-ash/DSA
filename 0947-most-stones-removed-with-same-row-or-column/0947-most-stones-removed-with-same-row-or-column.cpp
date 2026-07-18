class DisjointSet {
public:
    vector<int> parent;      // FIX: was vector<pair<int,int>> — you don't need pairs here,
                              // just a single parent id per node (int), like your earlier code.
    vector<int> size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;    // works now since parent[i] is just an int
        }
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]); // Path Compression
    }

    void unionBySize(int u, int v) {
        int up_u = findUPar(u);
        int up_v = findUPar(v);

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        // KEY IDEA:
        // Instead of treating each STONE as a node, we treat each ROW and each COLUMN
        // as a node. Two stones are connected (can remove one via the other) if they
        // share a row OR a column. So we union: (that stone's row) with (that stone's column).
        //
        // This way, all stones that are transitively connected through shared rows/cols
        // end up in the same disjoint-set component automatically — we don't even need
        // to union stones with each other directly.

        // We need enough nodes to cover all possible row indices AND all possible col indices.
        // Since row indices and col indices can overlap in value (e.g., row 3 and col 3
        // are different things), we "shift" column indices by some offset so they never
        // collide with row indices in the same DSU array.
        //
        // A safe offset is 10001 (since constraints usually say coordinates go up to 10^4),
        // but to keep it general and safe for any input, let's just compute the max
        // row/col value dynamically and offset by (maxCol + 1).

        int maxRow = 0, maxCol = 0;
        for (auto& st : stones) {
            maxRow = max(maxRow, st[0]);
            maxCol = max(maxCol, st[1]);
        }

        int offset = maxRow + 1;              // columns will be shifted by this
        int totalNodes = offset + maxCol + 1; // total distinct row-nodes + col-nodes

        DisjointSet ds(totalNodes);

        // For every stone, union its row-node with its (shifted) col-node.
        for (auto& st : stones) {
            int row = st[0];
            int col = st[1] + offset;   // shift column so it doesn't clash with row ids
            ds.unionBySize(row, col);
        }

        // Now count the number of DISTINCT connected components that actually
        // contain at least one stone. We do this by finding the ultimate parent
        // (root) of each stone's row-node, and counting how many unique roots exist.
        //
        // Note: we only need to check the root of the ROW node (not the col node)
        // for each stone, because row and col of the same stone are already unioned
        // together — they share the same root.

        set<int> uniqueRoots;
        for (auto& st : stones) {
            int root = ds.findUPar(st[0]);   // root of this stone's row
            uniqueRoots.insert(root);
        }

        int numComponents = uniqueRoots.size();

        // THE CORE INSIGHT:
        // Within a single connected component of k stones, we can always remove
        // (k - 1) stones — keep removing any stone that still shares a row/col with
        // another remaining stone, until only 1 stone is left in that component.
        // So max stones removable = (total stones) - (number of components).

        return n - numComponents;
    }
};