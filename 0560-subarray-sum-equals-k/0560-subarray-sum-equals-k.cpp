class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> prefixcount;
        prefixcount[0] = 1; 
        for(int i = 0 ; i< n ; i++){
            sum = sum + nums[i];
             if (prefixcount.find(sum - k) != prefixcount.end()) {
                count = count +  prefixcount[sum - k];
            }
            prefixcount[sum]++;
        }
        return count ;
    }
};