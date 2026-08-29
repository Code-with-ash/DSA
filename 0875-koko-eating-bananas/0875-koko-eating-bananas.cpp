class Solution {
    private:
    long long find(int mid , vector<int>& piles){
        long long ans = 0 ;
        for(int i = 0 ; i < piles.size() ; i++){
            ans = ans + (piles[i]+mid-1) / mid ;
        }
        return ans ;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = 0 ;
        int low = 1 ;
        for(int i = 0 ; i < n ; i ++){
            high = max(high , piles[i]);
        }
        while(low<=high){
            int mid = (high-low)/2 + low ;
            long long caneat = find(mid , piles );
            if(caneat<=h){
                high = mid -1 ;
            }
            else{
                low = mid + 1 ;
            }
        }
        return low ;
    }
};