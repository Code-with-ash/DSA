class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        // we just need a largest element and second largest element 
        int largestnum = INT_MIN ;
        int secondlargestnum = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]>largestnum){
                secondlargestnum = largestnum;
                largestnum = nums[i];
            }
            else if(nums[i]>secondlargestnum){
                secondlargestnum = nums[i];
            }
        }
        return (largestnum-1) * (secondlargestnum-1);
    }
};