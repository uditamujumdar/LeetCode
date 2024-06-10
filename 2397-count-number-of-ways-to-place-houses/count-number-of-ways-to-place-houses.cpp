class Solution {
public:
int mod=1e9+7;  
    int f(int n, vector<int>&dp){
        if(n<=0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int place=f(n-2,dp)%mod;
        int notplace=f(n-1,dp)%mod;

        return dp[n]=(place%mod + notplace%mod)%mod;
    }

    int countHousePlacements(int n) {
        vector<int>dp(n+1,-1);
        return ((long long)f(n,dp)*(long long)f(n,dp))%mod;
    }
};
