class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // distance to itself = 0
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // fill edges
        for (auto& it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2]; // undirected
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != 1e9 &&  dist[via][j] != 1e9) {
                      dist[i][j] = min(dist[i][j],dist[i][via] +  dist[via][j]); 
                    }
                }
            }
        }
        int cityno = -1;
        int cntcity = n;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold){
                    // valid condition 
                    count ++;
                }
            }
            if(count <= cntcity){
                // might be my answer but i need maximum number 
                cityno = i ;
                cntcity = count ; 
            }
        }
        return cityno ;
    }
};