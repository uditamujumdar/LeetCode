class Solution {
public:
    int mod=1e9+7;
    int f(int i, int j, int sum, int k, vector<vector<int>>&v, vector<vector<vector<int>>>&dp){
        if(i>=v.size() || j>=v[0].size()){
            return 0;
        }
        if(i==v.size()-1 && j==v[0].size()-1){
            sum=(sum+v[i][j])%k;
            if(sum%k==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][sum]!=-1){
            return dp[i][j][sum];
        }
        int down=f(i+1, j, (sum+v[i][j])%k, k, v, dp);
        int right=f(i, j+1, (sum+v[i][j])%k, k, v, dp);

        return dp[i][j][sum]=(down%mod +right%mod )%mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k+1,-1)));

        return f(0,0,0,k,grid,dp);
    }
};