class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]==0 && n == 1) return true;

        int maxi= 0; // max index i can go to 
        for(int i = 0 ; i < n ; i++){
            if(nums[i]==0){
                if(maxi > i){
                    continue ;
                }else{
                    break ;
                }
            }
            maxi = max(maxi , nums[i] + i );
            if(maxi >= n-1) return true ;
        }
          if(maxi >= n-1) return true ;
        return false ;
    }
};