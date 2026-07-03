class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // build graph
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        // push all nodes with indegree 0
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) q.push(i);

        // bfs
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return count == numCourses;  // no cycle if all nodes processed
    }
};