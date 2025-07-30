class Solution {
    int mod=1e9+7;
public:
    int f(int i, int j, int moves, int maxi, int m, int n, vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || i>=m || j>=n){
            return 1;
        }
        if(maxi==moves){
            return 0;
        }
        if(dp[i][j][moves]!=-1){
            return dp[i][j][moves];
        }
        int ans=0;
        ans = (ans + f(i, j-1, moves+1, maxi, m, n, dp)) % mod;
        ans = (ans + f(i, j+1, moves+1, maxi, m, n, dp)) % mod;
        ans = (ans + f(i+1, j, moves+1, maxi, m, n, dp)) % mod;
        ans = (ans + f(i-1, j, moves+1, maxi, m, n, dp)) % mod;

        dp[i][j][moves]=ans;

        return dp[i][j][moves] % mod;
    }

    int findPaths(int m, int n, int maxm, int srow, int scol) {
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(maxm+1, -1)));

        return f(srow, scol, 0, maxm, m, n, dp);
    }
};