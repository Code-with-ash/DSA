class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int s = n + n ;
        if(n == 1 ) return true ;
        int counter = 1 ;
        for(int i =0 ; i < s ; i++){
            if(nums[i%n]<=nums[(i+1) %n]){
                counter++;
                if(counter == n ) return true ;
            }else{
                counter = 1 ;
            }
        }
        return false ;
    }
};