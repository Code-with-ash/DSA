class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int left = 0 ; // on children
        int right = 0 ; // on cookies
        while((left<g.size() ) && (right < s.size())){
            if(s[right] >= g[left]){
                left++;
                right++;
            }
            else right++;
        }
        return left;
    }
};