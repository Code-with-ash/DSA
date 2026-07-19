class Solution {
    private: 
    int timer = 1;
    private :
    void dfs(int node , int parent , vector<int>& visited , vector<int> adj[] , int tin[] , int low[] ,vector<vector<int>>& bridges ){
        // first we mark it visited 
        visited[node] = 1;
        tin[node] = low[node] = timer ; // time taken = low = timer
        timer++;

        // no we travel to further nodes attached to 0
        for(auto it : adj[node]){
            if(it == parent ) continue ; 
            if(visited[it] == 0 ){
                // idhr bhi aaye nhi hain toh dfs call kro 

                dfs(it , node , visited , adj , tin , low , bridges);

                // call hoke aagya toh low[node] ko update krdo 
                low[node] = min(low[node] , low[it]);
                if(low[it] > tin[node]){
                    // toh its a bridge as we cant reach to it other way 
                    bridges.push_back({it , node});
                }
            }
            else{
                // already visited 
               low[node] = min(low[node] , low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges; // we store bridge here 
        dfs(0 , -1 , visited , adj , tin , low , bridges);
        return bridges;
    }
};