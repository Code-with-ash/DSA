class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int n = nums.size();
        int high = n -1;
        while(low<=high){
            int mid = low + ((high-low)/2);
            if(nums[mid]==target) return mid;
            else if(nums[low]<=nums[mid]){
                // sorted half is left
                if(nums[low]<=target && nums[mid]>target){
                    high = mid -1;
                }
               else  low = mid + 1;
            }
            else if(nums[mid]<nums[high]){
                // sorted half is right
                if(nums[mid]<target && nums[high]>=target){
                    low = mid + 1;
                }
                else high = mid -1 ;
            }
        }
        return -1;
    }
};