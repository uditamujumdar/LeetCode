class Solution {
public:
    int solve(int ind, int canbuy, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(ind==n){
            return 0;
        }
        long profit=0;

        if(dp[ind][canbuy]!=-1){
            return dp[ind][canbuy];
        }

        if(canbuy){
            int buy=-prices[ind] + solve(ind+1, 0, prices, n, dp);
            int notbuy=0+ solve(ind+1, 1, prices, n, dp);
            profit=max(buy, notbuy);
        }
        else{
            int buy_=prices[ind]+solve(ind+1, 1, prices, n, dp);
            int notbuy_=0+solve(ind+1, 0, prices, n, dp);
            profit=max(buy_, notbuy_);
        }

        return dp[ind][canbuy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp (n+1, vector<int>(2, -1));
        return solve(0,1,prices,n,dp);
    }
};