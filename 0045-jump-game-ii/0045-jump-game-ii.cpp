class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // already at the end, no jumps needed

        int jumps = 0;
        int currentEnd = 0;    // farthest index reachable with `jumps` jumps so far
        int farthest = 0;      // farthest index reachable with one more jump

        for (int i = 0; i < n - 1; i++) { // no need to process last index
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd) {        // exhausted current jump's range
                jumps++;
                currentEnd = farthest;
                if (currentEnd >= n - 1) break; // reached or passed the end
            }
        }
        return jumps;
    }
};