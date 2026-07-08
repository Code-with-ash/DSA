class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse it
        vector<vector<int>> reversed(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int node = graph[i][j];
                reversed[node].push_back(i);
            }
        }

        // now indegree calc
        vector<int> indegree(graph.size());
        for (int i = 0; i < reversed.size(); i++) {
            for (int j = 0; j < reversed[i].size(); j++) {
                int node = reversed[i][j];
                indegree[node]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < graph.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < reversed[node].size(); i++) {
                indegree[reversed[node][i]]--;
                if (indegree[reversed[node][i]] == 0)
                    q.push(reversed[node][i]);
            }
            ans.push_back(node);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};