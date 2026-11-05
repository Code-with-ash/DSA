class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map <int , int > mpp;
        mpp[0] = 1 ; // prefix - goal = 0 means 1 count ;
        int prefix =0;
        int ans = 0 ;
        for(int i = 0 ; i < nums.size();i++){
            prefix+=nums[i];
            ans = ans + mpp[prefix-goal];
            mpp[prefix]++;
        }
        return ans ;
    }
};