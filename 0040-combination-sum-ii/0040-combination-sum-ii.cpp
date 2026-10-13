class Solution {
private:
    void f(vector<int>& candidates, int target, vector<vector<int>>& ans,
           vector<int>& current, int index, int n) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (target < 0 || index == n)
            return;

        // PICK: use candidates[index] once, move to next index
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            f(candidates, target - candidates[index], ans, current, index + 1, n);
            current.pop_back(); // backtrack
        }

        // NOT PICK: skip all duplicates of candidates[index]
        while (index + 1 < n && candidates[index] == candidates[index + 1])
            index++;
        f(candidates, target, ans, current, index + 1, n);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Step 1: sort
        vector<vector<int>> ans;
        vector<int> current;
        int n = candidates.size();
        f(candidates, target, ans, current, 0, n);
        return ans;
    }
};
