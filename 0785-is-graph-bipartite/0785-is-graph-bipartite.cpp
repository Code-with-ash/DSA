class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), -1);
    queue<pair<int,int>> q;

    for(int i = 0; i < graph.size(); i++){
        if(color[i] == -1){
            color[i] = 0;
            q.push({i, 0});        // Bug 1 fixed

            while(!q.empty()){
                int curr_val   = q.front().first;
                int curr_color = q.front().second;
                q.pop();           // Bug 3 fixed

                for(int j = 0; j < graph[curr_val].size(); j++){
                    if(color[graph[curr_val][j]] == -1){
                        color[graph[curr_val][j]] = 1 - curr_color;
                        q.push({graph[curr_val][j], 1 - curr_color});  // Bug 2 fixed
                    }
                    else if(color[graph[curr_val][j]] == curr_color)
                        return false;
                }
            }
        }
    }
    return true;
}
};