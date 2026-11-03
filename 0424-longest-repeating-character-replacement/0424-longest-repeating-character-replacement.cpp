class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int n = s.size();
        int ans = 0;
        int l = 0;
        int flag = 0;
        int maxfreq = 0;
        char maxfreqelement = 'x';
        // window length - maxfreq
        for (int r = 0; r < n; r++) {

            mpp[s[r]]++;
            maxfreq = max(maxfreq, mpp[s[r]]);

            while ((r - l + 1) - maxfreq > k) {
                mpp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};