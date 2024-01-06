class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
        }
        
        return dp[i][j]=max( solve(i-1,j,s,t,dp), solve(i,j-1,s,t,dp) );
       
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.length();
	    int m=word2.length();
	    vector<vector<int>>dp(n, vector<int>(m, -1));
        int lcs= solve(n-1, m-1, word1, word2, dp);
        int x1=m-lcs;
        int x2=n-lcs;
        
        return x1+x2;
    }
};