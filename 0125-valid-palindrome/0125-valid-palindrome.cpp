class Solution {
public:
    bool isPalindrome(string s) {
        // for(char c : s){
        //     if(isalnum(c)) str+= tolower(c);
        // }
        int i = 0 ; int j = s.size()-1;
        while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue ;
            }
            if(!isalnum(s[j])){
                j-- ;
                continue ;
            } 
            if(tolower(s[i])!=tolower(s[j])) return false ;
            i++;
            j--;
        }
        return true ;
    }
};