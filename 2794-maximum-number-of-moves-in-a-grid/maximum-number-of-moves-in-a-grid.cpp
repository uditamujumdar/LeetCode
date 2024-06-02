class Solution {
public:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(row<0||col<0||col>=n||row>=m){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int a=0,b=0,c=0;
        
        if(row-1>=0 && col+1<n && grid[row-1][col+1]>grid[row][col]){
            a=1+f(row-1,col+1,grid,dp);
        }
        if(row>=0 && col+1<n && grid[row][col+1]>grid[row][col]){
            b=1+f(row, col+1, grid, dp);
        }
        if(row+1<m && col+1<n && grid[row+1][col+1]>grid[row][col]){
            c=1+f(row+1, col+1, grid, dp);
        }
        return dp[row][col]=max({a,b,c});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));

        for(int i=0;i<m;i++){
            ans=max(ans, f(i,0,grid,dp));
        }
        return ans;
    }
};