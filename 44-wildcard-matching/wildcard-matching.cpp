class Solution {
public:
    bool f(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(i<0 && j<0){
            return true;
        }
        if(i<0 && j>=0){
            return false;
        }
        if(i>=0 && j<0){
            for(int k=0;k<=i;k++){
                if(s[k]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j] || s[i]=='?'){
            return dp[i][j]=f(i-1,j-1,s,t,dp);
        }

        if(s[i]=='*'){
            return dp[i][j]= f(i-1,j,s,t,dp) || f(i,j-1,s,t,dp);
        }

        return 0;
    }

    bool isMatch(string str, string pattern) {
        int n=str.size();
        int m= pattern.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, pattern, str, dp);
    }
};