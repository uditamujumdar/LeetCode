class Solution {
public:
    int f(int r, int c,vector<vector<int>>&mat,vector<vector<int>>&vis,vector<vector<int>>&dp){
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int n=mat.size();
        int m=mat[0].size();
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int ans=1;
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nc<m && nr<n && !vis[nr][nc] && mat[nr][nc]>mat[r][c]){
                ans=max(ans, 1+f(nr,nc,mat,vis,dp));
            }
        }
        vis[r][c]=0;
        return dp[r][c]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=-1;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<vector<int>>dp(n, vector<int>(m, -1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, f(i,j,mat,vis,dp));
            }
        }
        return ans;
    }
};