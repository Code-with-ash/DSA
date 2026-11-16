class Solution {
private:
    int atMostK(vector<int>& nums, int k) {
        int l = 0;
        int ans = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < nums.size(); r++) {

            mp[nums[r]]++;

            while (mp.size() > k) {
                mp[nums[l]]--;

                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }

                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};