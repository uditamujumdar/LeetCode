class Solution {
public:
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>&dp){
        int n=mat.size();
        int m=mat[0].size();
        if(i<0||j<0||i>=n||j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int u=0,d=0,l=0,r=0;
        if(i-1>=0 && mat[i-1][j]>mat[i][j]){
            u=1+f(i-1,j,mat,dp);
        }
        if(i+1<n && mat[i+1][j]>mat[i][j]){
            d=1+f(i+1,j,mat,dp);
        } 
        if(j-1>=0 && mat[i][j-1]>mat[i][j]){
            l=1+f(i,j-1,mat,dp);
        }
        if(j+1<m && mat[i][j+1]>mat[i][j]){
            r=1+f(i,j+1,mat,dp);
        }

        return dp[i][j]=max(u,max(d,max(l,r)));
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>>dp(n, vector<int>(m, -1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, 1+f(i,j,matrix,dp) );
            }
        }
        return ans;
    }
};