class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();

        int i=0, j=n*m-1;

        while(i<=j){
            int mid=i+(j-i)/2;
            int row=mid/m;
            int col=mid%m;
            
            if(mat[row][col]==target){
                return true;
            }
            else if(mat[row][col]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }

        return false;
    }
};