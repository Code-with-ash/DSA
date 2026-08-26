class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        int longest = 0;

        for (int x : st) {
            if (st.find(x - 1) == st.end()) { // start of a sequence
                int curr = x;
                int len = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }
        return longest ;
    }
};