class Solution {
private:
    void f(vector<int>& candidates, int target, vector<vector<int>>& ans, 
           vector<int>& current, int index, int n) {
        
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        
        // Base case: if target goes negative or we've exhausted candidates
        if (target < 0 || index == n) {
            return;
        }
        
        // PICK: Include candidates[index] (can reuse same element)
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            f(candidates, target - candidates[index], ans, current, index, n);
            current.pop_back(); // Backtrack
        }
        
        // NOT PICK: Skip candidates[index] and move to next
        f(candidates, target, ans, current, index + 1, n);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        int n = candidates.size();
        f(candidates, target, ans, current, 0, n);
        return ans;
    }
};