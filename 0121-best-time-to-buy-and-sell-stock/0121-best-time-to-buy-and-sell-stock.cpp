class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0 ;
        int right = 1 ;
        int ans = 0 ;
        while(left<right && right < n ){
            if(prices[left]>=prices[right]){
                left = right ;
            right++;
            }
            else{
                ans= max(ans , prices[right]-prices[left]);
                right++;
            }
        }
        return ans ;
    }
};