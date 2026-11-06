class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
    vector<int>& queries) {
        // sort logs 
        sort(logs.begin(), logs.end(),
        [](auto& a, auto& b) { return a[1] < b[1]; });
        // sort queries 
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        unordered_map<int, int> freq;   // server -> number of logs currently in window
        vector<int> ans(queries.size());
        int left = 0;
        int right = 0;

        for (auto &[queryTime, idx] : q) {

            int start = queryTime - x;

            // Add all logs with time <= queryTime
            while (right < logs.size() && logs[right][1] <= queryTime) {
                int server = logs[right][0];
                freq[server]++;
                right++;
            }

            // Remove logs with time < start
            while (left < right && logs[left][1] < start) {
                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0)
                    freq.erase(server);

                left++;
            }

            // Active servers = freq.size()
            // Inactive servers = n - active
            ans[idx] = n - freq.size();
        }

        return ans;
    }
};