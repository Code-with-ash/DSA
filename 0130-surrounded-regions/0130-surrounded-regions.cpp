class Solution {
    void dfs(int row , int col ,vector<vector<int>>& visited , vector<vector<char>>&board){
        int n = board[0].size(); // col
        int m = board.size(); // row;
        visited[row][col]=1;
        vector<int> delrow = {-1 , 0 , 1 , 0};
        vector<int> delcol = {0 , 1 , 0 , -1};
        for(int i = 0 ; i < 4 ; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && board[nr][nc]=='O'){
               dfs(nr , nc , visited , board) ;
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board[0].size(); // col
        int m = board.size(); // row;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0 ; i < n;i++){
            if(board[0][i]=='O' && !visited[0][i]){
                dfs(0 , i , visited , board);
            }
            if(board[m-1][i]=='O' && !visited[m-1][i]){
                dfs(m-1 , i , visited , board);
            }
        }
        for(int i = 0 ; i < m ;i++){
            if(board[i][0]=='O' && !visited[i][0]){
                dfs(i , 0 , visited , board);
            }
            if(board[i][n-1]=='O' && !visited[i][n-1]){
                dfs(i, n-1 , visited , board);
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};