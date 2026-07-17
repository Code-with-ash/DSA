class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        parent.resize(n + 1);  // for both 0 based and 1 based
        size.resize(n + 1, 1); // all have size 1

        for (int i = 0; i <= n; i++) {
            parent[i] = i; // all are parents of itself
        }
    }

    int findUpar(int node) {
        if (node == parent[node]) {
            return node;
        }
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        // map initalistion
        unordered_map<string, int> mpp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mailid = accounts[i][j];
                if (mpp.find(mailid) == mpp.end()) {
                    // doesnt exist in map
                    mpp[mailid] = i;
                } else {
                    ds.unionbysize(i, mpp[mailid]);
                }
            }
        }
        vector<string> mailids[n];
        // now we iterate in map
        for (auto it : mpp) {
            // cout << it.first << " " << it.second << endl;
            string mailid = it.first;
            int node = ds.findUpar(it.second);
            mailids[node].push_back(mailid);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (!mailids[i].empty()) {
                sort(mailids[i].begin(), mailids[i].end()); // Bug 3 fixed
                vector<string> temp;
                temp.push_back(accounts[i][0]); // add name
                for (auto& mail : mailids[i])
                    temp.push_back(mail); // Bug 1,2 fixed
                ans.push_back(temp);
            }
        }
    return ans;
}
};