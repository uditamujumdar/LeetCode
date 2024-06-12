class Solution {
public:
    int f(int ind, int len, int sum, string& s,  int k, vector<vector<int>>&dp){
        if(ind<0){
            return 0;
        }
        if(dp[ind][len]!=-1){
            return dp[ind][len];
        }
        
        int notpick=0, pick=0;
        notpick=f(ind-1, len, sum, s, k, dp);

        if( sum+(s[ind]-'0')*pow(2,len)<=k){
            pick=1+f(ind-1,len+1,sum+(s[ind]-'0')*pow(2,len),s,k,dp);
        }

        return dp[ind][len]=max(pick, notpick);
    }

    int longestSubsequence(string s, int k) {
        int n=s.length();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return f(n-1,0,0,s,k,dp);
    }
};