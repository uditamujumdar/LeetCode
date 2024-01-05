class Solution {
public:
    int solve(int ind,int canbuy,int cap,vector<int>& prices,int n, 
        vector<vector<vector<int>>>& dp){
        if(ind==n || cap==0){
            return 0;
        }
        long profit=0;

        if(dp[ind][canbuy][cap]!=-1){
            return dp[ind][canbuy][cap];
        }

        if(canbuy){
            int buy=-prices[ind] + solve(ind+1, 0, cap, prices, n, dp);
            int notbuy=0+ solve(ind+1, 1, cap, prices, n, dp);
            profit=max(buy, notbuy);
        }
        else{
            int buy_=prices[ind]+solve(ind+1, 1, cap-1, prices, n, dp);
            int notbuy_=0+solve(ind+1, 0, cap, prices, n, dp);
            profit=max(buy_, notbuy_);
        }

        return dp[ind][canbuy][cap]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0,1,2,prices,n,dp);
    }
};