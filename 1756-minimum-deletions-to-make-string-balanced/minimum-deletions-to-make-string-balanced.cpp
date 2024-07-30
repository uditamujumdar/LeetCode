class Solution {
public:
    int f(int ind, char prev, string& s, vector<vector<int>>&dp){
        if(ind>=s.size()){
            return 0;
        }
        if(dp[ind][prev-'a']!=-1){
            return dp[ind][prev-'a'];
        }
        int pick=0;
        int notpick=f(ind+1, prev, s, dp);
        if(s[ind]>=prev){
            pick=1+f(ind+1, s[ind], s, dp);
        }
        return dp[ind][prev-'a']=max(pick, notpick);
    }
    
    int minimumDeletions(string s) {
        int n=s.length();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return n-f(0, 'a', s, dp);
    }
};