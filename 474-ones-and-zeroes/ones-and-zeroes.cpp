class Solution {
public:
    int count(string s){
        int cnt=0;
        for(auto it: s){
            if(it=='0'){
                cnt++;
            }
        }
        return cnt;
    }

    int f(int ind,int m,int n,vector<string>&strs,vector<vector<vector<int>>>&dp){
        if(ind>=strs.size()){
            return 0;
        }
        if(dp[ind][m][n]!=-1){
            return dp[ind][m][n];
        }
        int pick=0, notpick=0;
        notpick=f(ind+1,m,n,strs,dp);

        string s=strs[ind];
        int cntz=count(s);
        int cnto=s.length()-cntz;
        if(m-cntz>=0 && n-cnto>=0){
            pick=1+f(ind+1, m-cntz, n-cnto, strs,dp);
        }
        return dp[ind][m][n]=max(pick, notpick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        vector<vector<vector<int>>>dp(len, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return f(0,m,n,strs,dp);
    }
};