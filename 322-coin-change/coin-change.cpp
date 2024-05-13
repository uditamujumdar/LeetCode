class Solution {
public:
    int f(int ind, vector<int>& coins, int amt, vector<vector<int>>& dp){
        if(ind==0){
            if(amt%coins[0]==0){
                return amt/coins[0];
            }
            return 1e9;
        }
        
        if(dp[ind][amt]!=-1){
            return dp[ind][amt];
        }

        int take=INT_MAX;
        if(coins[ind]<=amt){
            take=1+f(ind, coins, amt-coins[ind], dp);
        }
        int nottake=f(ind-1, coins, amt, dp);

        return dp[ind][amt]=min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amt+1, -1));

        int ans=f(n-1, coins, amt, dp);

        if(ans>=1e9){
            return -1;
        }

        return ans;
    }
};