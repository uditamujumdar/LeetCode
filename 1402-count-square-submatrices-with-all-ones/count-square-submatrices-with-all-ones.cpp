class Solution {
public:
    int f(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=0;

        if(mat[i][j]==1){
            ans=1+min({f(i-1, j, mat, dp), f(i-1, j-1, mat, dp), f(i, j-1, mat, dp)});
        }

        return dp[i][j]=ans;
    }
    
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=f(i, j, mat, dp);
            }
        }

        return ans;
    }
};