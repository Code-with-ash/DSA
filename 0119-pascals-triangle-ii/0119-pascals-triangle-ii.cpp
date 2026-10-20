class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> ansvec;
        ansvec.push_back(ans);
        rowIndex = rowIndex+1;
        for(int i = 1 ; i < rowIndex ; i++){
            ans = ans*(rowIndex-i);
            ans = ans / i;
            ansvec.push_back(ans);
        }
        return ansvec;
    }
};