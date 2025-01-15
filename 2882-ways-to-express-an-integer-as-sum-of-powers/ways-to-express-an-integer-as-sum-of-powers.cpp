class Solution {
public:
    int mod=1e9+7;
    int f(int curr, long long currsum, int x, int n, vector<vector<int>>&dp){
        if(currsum==n){
            return 1;
        }
        if(currsum>n || curr>n){
            return 0;
        }
        if(dp[curr][currsum]!=-1){
            return dp[curr][currsum];
        }
        long long temp=pow(curr, x);
        long long pick=f(curr+1, currsum+temp, x, n, dp);
        long long notpick=f(curr+1, currsum, x, n, dp);

        return dp[curr][currsum]=(pick+notpick)%mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return f(1,0,x,n,dp);
    }
};