class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int n= nums.size()  ;
      int counter = 0;
      int maxcount = 0;
      for(int i = 0 ; i<n ; i++){
        if(nums[i]==1){
            counter ++;
            maxcount = max(counter , maxcount);
        }
        else{
        counter = 0;
        }
      }
      return maxcount;
    }
};