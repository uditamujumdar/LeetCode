class Solution {
public:
    int f(int ind, string& s, vector<string>&dict, vector<int>&dp){
        if(ind>=s.length()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=1+f(ind+1, s,dict,dp);
        string t="";
        for(int i=ind;i<s.size();i++){
            t.push_back(s[i]);
            if(find(dict.begin(), dict.end(), t)!=dict.end()){
                ans=min(ans, f(i+1,s,dict,dp));
            }
        }
        return dp[ind]=ans;
    }

    int minExtraChar(string s, vector<string>& dict) {
        int n=s.length();
        vector<int>dp(n, -1);
        return f(0, s, dict, dp);
    }
};