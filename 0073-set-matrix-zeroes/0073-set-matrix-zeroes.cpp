class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;

        int m = matrix.size();    // rows
        int n = matrix[0].size(); // cols
        int col0 = 1;             // marker for first column

        // Step 1: mark the first row/col
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = 0; // check col0 separately
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // mark row
                    matrix[0][j] = 0;  // mark col
                }
            }
        }

        // Step 2: zero the inner cells
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: zero the first row if needed
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: zero the first col if needed
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
