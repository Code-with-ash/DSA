class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int posindex = 0 ;
        int negindex = 1;
        for(int i = 0 ; i< n; i++){
            if(nums[i]>0){
                ans[posindex] = nums[i];
                posindex = posindex+2;
            }
            else{
                ans[negindex] = nums[i];
                negindex= negindex+2;
            }
        }
        return ans;
    }
};