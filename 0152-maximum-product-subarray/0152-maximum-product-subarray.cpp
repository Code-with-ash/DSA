class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxproduct = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1; // when u see zero u start a new array so product
                            // starts again from 1
            if (suffix == 0) suffix = 1;
            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];
            maxproduct = max(maxproduct, max(prefix, suffix));
        }
        return maxproduct;
    }
};