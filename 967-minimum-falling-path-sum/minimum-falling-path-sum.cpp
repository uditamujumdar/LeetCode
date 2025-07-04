class Solution {
public:
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        int n=mat.size();
        if(i==n-1){
            return mat[i][j];
        }
        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }
        int d=mat[i][j]+f(i+1, j, mat, dp);
        int dr=INT_MAX;
        if(j+1<n){
            dr=mat[i][j]+f(i+1, j+1, mat, dp);
        }
        int dl=INT_MAX;
        if(j-1>=0){
            dl=mat[i][j]+f(i+1, j-1, mat, dp);
        }

        return dp[i][j]=min({d, dr, dl});
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        
        vector<vector<int>>dp(n, vector<int>(n, INT_MIN));

        int ans=INT_MAX;

        for(int j=0;j<n;j++){
            ans=min(ans, f(0, j, mat, dp));
        }   

        return ans;
    }
};