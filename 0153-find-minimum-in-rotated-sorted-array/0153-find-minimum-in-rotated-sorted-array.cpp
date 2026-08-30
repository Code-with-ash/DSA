class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0 ;
        int high = n-1 ;
        int ans = INT_MAX ;
        while(low<=high){
            int mid = (high-low)/2 + low ;
            ans = min(ans , nums[mid]);
            if(nums[mid]>nums[high]){
                // rotated hai answer right mai hoga 
                low = mid + 1 ;
            }else{
                high = mid -1 ;
            }
        }
        return ans ;
    }
};