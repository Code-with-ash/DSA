class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; // number and frequency 
        int n = nums.size();
        unordered_set<int> set ;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            set.insert(nums[i]);
        }
        vector<int> ans;
        while (k > 0) {
            int max = INT_MIN;
            int num = 0 ;
            for (auto& it : mpp) {
                if(it.second > max && set.find(it.first)!= set.end()){
                  max = it.second ;
                  num = it.first ;
                }
            }
            set.erase(num);
            ans.push_back(num);
            k--;
        }
        return ans ;
    }
};