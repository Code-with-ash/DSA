class Solution {
    // formula for  NcR n factorial / n-r factorial * r factorial 
public:
    vector<vector<int>> generate(int numRows) {
        int ans = 1;
        vector<int> inner ;
        vector<vector<int>> outer;
        for(int i = 1 ;i<=numRows ; i++){
            inner.push_back(ans);
            for( int j = 1; j<i; j++ ){
                ans = ans * (i-j);
                ans= ans/j;
                inner.push_back(ans);
            }
            ans = 1;
            outer.push_back(inner);
            inner.clear();
        }
        return outer;
    }
};