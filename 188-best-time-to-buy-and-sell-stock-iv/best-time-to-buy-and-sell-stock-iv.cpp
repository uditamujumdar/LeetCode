class Solution {
public:
    int solve(int i,int canbuy,int cap,int n,vector<int>&prices, 
        vector<vector<vector<int>>>&dp){
        if(cap==0)
        return 0;

        if(i==n){
        return 0;
        }

        if(dp[i][canbuy][cap]!=-1){
        return dp[i][canbuy][cap];
        }

        int profit=0;

        if(canbuy){
            int buy=-prices[i]+solve(i+1,0,cap,n,prices,dp);
            int notbuy=solve(i+1,1,cap,n,prices,dp);
            profit=max(buy,notbuy);
        }
        else{
            int buy_=prices[i]+solve(i+1,1,cap-1,n,prices,dp);
            int notbuy_=solve(i+1,0,cap,n,prices,dp);
            profit=max(buy_, notbuy_);
        }
        return dp[i][canbuy][cap]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solve(0,1,k,n,prices,dp);
    }
};