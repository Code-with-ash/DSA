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

    int findUPar(int node) { // Ultimate parent node
        if (node == parent[node])
            return node; // u r standing on parent node , thats what u needed

        return parent[node] = findUPar(parent[node]); // Path Compression
    }

    void unionBySize(int u, int v , int& extraedge) {
        int ulp_u = findUPar(u); // ultimate parent of u 
        int ulp_v = findUPar(v); // ultimate parent of v 

        if (ulp_u == ulp_v){
            extraedge++;
            return;
        } // abe same usme khda h aur union kru tera?? 

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
}; class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
    return -1;
        int cables = connections.size();
        DisjointSet ds(n);

        // made a mst
        int extraedge = 0 ;
        for(int i = 0 ; i < connections.size() ; i++){
            int from = connections[i][0];
            int to = connections[i][1];
            ds.unionBySize(from , to , extraedge);
        }

        // find count , number of component = 3 , number of extra edge = 2 ,
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(ds.parent[i] == i){
                count++;
            }
        }


       if(extraedge >= count -1){
                    return count - 1 ;
                   }
             else return -1;
    }
};