class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int counter = 0;
        vector<int> rowsum(mat.size(), 0);
        vector<int> colsum(mat[0].size(), 0);
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++) {
                rowsum[i] += mat[i][j];
                colsum[j] += mat[i][j]; // ← both at once
            }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1 && rowsum[i] == 1 && colsum[j] == 1)
                    counter++;
            }
        }
        return counter;
    }
};