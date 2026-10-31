class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int r = n-1;
        int leftsum = 0;
        int rightsum = 0;
        for(int i = 0 ; i < k ; i++){
            leftsum+=cardPoints[i]; // from 0 to k-1 index
        }
        int maxsum = leftsum ;
        int sum = 0;
        for(int i = k-1 ; i >=0 ; i--){
            leftsum = leftsum - cardPoints[i];
            rightsum = rightsum + cardPoints[r];
            r--;
            sum = leftsum + rightsum ;
            maxsum = max(maxsum , sum);
        }
        return maxsum;
    }
};