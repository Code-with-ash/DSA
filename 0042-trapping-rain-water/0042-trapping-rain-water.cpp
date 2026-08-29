class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int suffixmax[n];
        suffixmax[n-1] = height[n-1];
        for(int i = n-2 ; i >=0  ; i--){
            suffixmax[i] = max(suffixmax[i+1] , height[i]);
        }
        int ans = 0 ;
        int leftmax = height[0];
        for(int i = 0 ; i < n ; i++){
            int rightmax = suffixmax[i];
            int leftmax = max(leftmax , height[i]);
            if(height[i]<leftmax && height[i]<rightmax){
                ans = ans + min(leftmax , rightmax) - height[i];
            }
        }
        return ans ;
    }
};