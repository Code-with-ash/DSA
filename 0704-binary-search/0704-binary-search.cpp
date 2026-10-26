class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) {
            if(nums[0]==target) return 0;
            else return -1 ;
        }
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};