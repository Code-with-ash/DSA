class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string , vector<string>> mpp;
        for(auto& s : strs){
            vector<int> freq (26 , 0);
            for(char c : s){
                freq[c-'a']++;
            }
            string key = "";
            for(int count : freq){
                key = key + to_string(count) + "#"; 
            }
            mpp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& it : mpp){
            ans.push_back(it.second);
        }
        return ans ;
    }
};