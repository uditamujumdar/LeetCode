class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }

        if(buy){
            return dp[ind][buy]=max(-prices[ind]+solve(ind+1, 0, prices, dp),
                        0+solve(ind+1, 1, prices, dp));
        }

        //only change is to move to index+2, as you cannot buy stock the very next day
        else{
            return dp[ind][buy]= max(prices[ind]+solve(ind+2, 1, prices, dp),
                        0+solve(ind+1, 0, prices, dp));
        } 
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};