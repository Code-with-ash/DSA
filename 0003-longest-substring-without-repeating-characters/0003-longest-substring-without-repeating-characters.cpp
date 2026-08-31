class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0;
        int right = 0;
        int n = s.size();
        if (n == 0)
            return 0;
        int ans = 0;
        while (right < n) {
            if (st.find(s[right]) == st.end()) {
                // exist nhi krta
                ans = max(ans, right - left + 1);
                st.insert(s[right]);
                right++;
            } else {
                st.erase(s[left]);
                left++;
            }
        }
        return ans ;
    }
};