class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();    // rows
        int n = matrix[0].size(); // cols

        // transpose 
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j< m ; j++){
                if(i!=j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
    reverse(matrix[i].begin(), matrix[i].end());
}
    }
};