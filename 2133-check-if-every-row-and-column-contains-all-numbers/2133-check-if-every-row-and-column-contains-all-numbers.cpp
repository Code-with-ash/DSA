class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_set<int> set;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (set.find(matrix[i][j]) != set.end())
                    return false;
                if (matrix[i][j] < 1 || matrix[i][j] > matrix.size())
                    return false;
                else
                    set.insert(matrix[i][j]);
            }
            set.clear();
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (set.find(matrix[j][i]) != set.end())
                    return false;
                if (matrix[j][i] < 1 || matrix[j][i] > matrix.size())
                    return false;
                else
                    set.insert(matrix[j][i]);
            }
            set.clear();
        }
        return true;
    }
};