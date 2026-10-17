class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()){
            return 0 ;
        }
        int j = 0;
        for(int i = 0 ; i< n-1 ; i++){
            if(nums[i]!=nums[i+1]){
                nums[j]=nums[i];
                j++;
            }
        }
         nums[j] = nums[nums.size() - 1];
        j++;
        return j;
    }
};