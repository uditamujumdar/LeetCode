class Solution {
public:
    int f(int i ,int n , vector<int> &v ,vector<vector<int>> &dp){
        if(n== 0) return 0;
        if(i == 0){
            return n;
        }
        if(dp[i][n] != -1) return dp[i][n];
        int notpick = f(i-1,n,v,dp);
        int pick = 1e9;
        if(n-v[i] >= 0){
            pick = 1 + f(i,n- v[i] ,v,dp);
        }
        return dp[i][n] = min(pick , notpick);
    }

    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i<=100 ;i++){
            v.push_back(i*i);
        }
        vector<vector<int>> dp( v.size(),vector<int>(n+1,-1) );
        return f(99,n,v,dp);
    }
};