class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // swap 0 with non zero number 
        int left = 0 ;
        int right = 0 ;
        while(left < n && right < n){
            if(nums[left]==0 && nums[right]==0){
                right++;
                continue ;
            }
            swap(nums[left],nums[right]);
            left++;
            right ++;
        }
    }
};