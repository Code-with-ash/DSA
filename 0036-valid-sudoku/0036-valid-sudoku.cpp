class Solution {
    private :
    bool f(int i , int j ,vector<vector<char>>& board){
        unordered_set<char> st ;
        for(int row = i ; row < i + 3 ; row ++){
            for(int col = j ; col < j + 3 ; col++){
                if(board[row][col]=='.') continue ;
                if(st.find(board[row][col])!=st.end()) return false ;
                st.insert(board[row][col]);
            }
        }
        return true ;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> set ;
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j]=='.') continue ;
                if(set.find(board[i][j])!= set.end()){
                    // it already exists 
                    return false ;
                }
                set.insert(board[i][j]);
            }
            set.clear();
        }
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[j][i]=='.') continue ;
                if(set.find(board[j][i])!= set.end()){
                    // it already exists 
                    return false ;
                }
                set.insert(board[j][i]);
            }
            set.clear();
        }
        for(int i = 0 ; i < 9 ; i = i + 3 ){
            for(int j = 0 ; j < 9 ; j = j + 3){
            if(!f(i , j , board)) return false ;;
            }
        }
        return true  ;
    }
};