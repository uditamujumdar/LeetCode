class Solution {
public:
    int f(int ind, int prev, vector<vector<int>>&pairs, vector<vector<int>>&dp){
        if(ind>=pairs.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int notpick=f(ind+1,prev,pairs,dp);
        int pick=0;

        if(prev==-1 || pairs[ind][0]>pairs[prev][1]){
            pick=1+f(ind+1, ind, pairs, dp);
        }

        return dp[ind][prev+1]=max(pick,notpick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return f(0,-1,pairs,dp);
    }
};