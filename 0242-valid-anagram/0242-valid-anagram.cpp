class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26]={0};
        int n = s.size();
        int m = t.size();
        if(m!=n) return false;
        for(int i = 0 ; i < n ; i++){
            freq[s[i]-'a']++;
        }
        for(int i = 0 ; i< m ; i++){
            if(freq[t[i]-'a']==0) return false;
            else{
                freq[t[i]-'a']--;
            }
        }
        return true;
    }
};