class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;  // avoid infinite loop

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n
                   && image[nr][nc] == originalColor){
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};