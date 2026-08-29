class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0 ;
        int high = row - 1;
        int tocheck = 0 ;
        if(matrix[0][0]>target) return false ;
        while(low<=high){
            int mid = (high-low)/2 + low ;
            if(matrix[mid][0]==target) return true ;
            if(matrix[mid][0]<target){
                low = mid+1 ;
            }
            else{
                high = mid -1;
            }
        }
        int rowss = high ;
        low = 0 ;
        high = col -1 ;
        while(low<=high){
            int mid = (high-low)/2 + low ;
            if(matrix[rowss][mid] == target) return true ;
            if(matrix[rowss][mid]<target){
                low = mid+1 ;
            }else{
                high = mid -1 ;
            }
        }
        return false ;
    }
};