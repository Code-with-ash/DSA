class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        sort(nums.begin() , nums.end());
        int lastnum = nums[n-1];
        int lastsecondnum = nums[n-2];
        product = (lastnum-1 ) * (lastsecondnum-1);
        return product ;
    }
};