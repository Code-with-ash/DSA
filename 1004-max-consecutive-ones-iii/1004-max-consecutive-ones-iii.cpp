class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // u can flip k number 0s 
        int l = 0 ;
        int r = 0 ;
        int n = nums.size();
        int flag = 0 ;
        int ans = 0;
        while(r<n){
            if(nums[r]==0){
                flag++;
            }
            while(flag > k){
                if(nums[l]==0){
                    flag--;
                }
                l++;
            }
            ans = max(ans , r-l+1);
            r++;
        }
        return ans ;
    }
};