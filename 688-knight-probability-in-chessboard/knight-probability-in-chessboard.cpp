class Solution {
public:
    double f(int n, int k, int row, int col,vector<vector<vector<double>>>&dp){
        if(row>=n || col>=n || row<0 || col<0){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[row][col][k]!=-1){
            return dp[row][col][k];
        }

        double sum=f(n,k-1,row-1,col-2,dp)+f(n,k-1,row-2,col-1,dp)+f(n,k-1,row+1,col+2,dp)+
                f(n,k-1,row+2,col+1,dp)+f(n,k-1,row-1,col+2,dp)+f(n,k-1,row-2,col+1,dp)+
                f(n,k-1,row+1,col-2,dp)+f(n,k-1,row+2,col-1,dp);

        sum=sum/8;
        return dp[row][col][k]=sum;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return f(n,k,row,column,dp);
    }
};