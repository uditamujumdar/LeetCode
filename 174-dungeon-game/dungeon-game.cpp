class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dun, vector<vector<int>>&dp){
        int n=dun.size();
        int m=dun[0].size();
        if(i==n-1 && j==m-1){
            return max(1, 1-dun[i][j]);
        }
        if(i>=n || j>=m){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int r=f(i, j+1, dun, dp);
        int d=f(i+1, j, dun, dp);

        int mini=min(r, d)-dun[i][j];

        return dp[i][j]=max(1, mini);
    }

    int calculateMinimumHP(vector<vector<int>>& dun) {
        int n=dun.size();
        int m=dun[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        return f(0, 0, dun, dp);
    }
};