class Solution {
public:
    int mod=1e9+7;
    int f(int ind, string&s, vector<int>&dp){
        if(ind>=s.length()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=0;
        vector<int>vis(26, 0);
        for(int i=ind;i<s.length();i++){
            if(vis[s[i]-'a']==1){
                continue;
            }
            vis[s[i]-'a']=1;
            ans+=(1+f(i+1,s,dp))%mod;
            ans=ans%mod;
        }
        return dp[ind]=ans;
    }

    int distinctSubseqII(string s) {
        int n=s.length();
        vector<int>dp(n+1, -1);
        return f(0,s,dp);
    }
};