class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curr;

        function<void(int, int)> dfs = [&](int idx, int segments) {
            if (segments == 4) {
                if (idx == s.size()) {
                    ans.push_back(curr.substr(0, curr.size() - 1)); // Remove last '.'
                }
                return;
            }

            if (idx >= s.size()) return;

            // Handle leading zero
            if (s[idx] == '0') {
                curr += "0.";
                dfs(idx + 1, segments + 1);
                curr.erase(curr.size() - 2);
                return;
            }

            int num = 0;

            for (int i = idx; i < s.size() && i < idx + 3; i++) {
                num = num * 10 + (s[i] - '0');

                if (num > 255) break;

                curr += s.substr(idx, i - idx + 1) + ".";
                dfs(i + 1, segments + 1);
                curr.erase(curr.size() - (i - idx + 2));
            }
        };

        dfs(0, 0);
        return ans;
    }
};