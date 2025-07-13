class Solution {
public:
    int f(int ind, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind>=prices.size() || k<=0){
            return 0;
        }
        if(dp[ind][buy][k]!=-1){
            return dp[ind][buy][k];
        }

        if(buy==1){
            int a=-prices[ind]+f(ind+1, 1-buy, k, prices, dp);
            int b=f(ind+1, buy, k, prices, dp);

            return dp[ind][buy][k]=max(a, b);
        }

        else{
            int a=prices[ind]+f(ind+1, 1-buy, k-1, prices, dp);
            int b=f(ind+1, buy, k, prices, dp);

            return dp[ind][buy][k]=max(a, b);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();

        // return f(0, 1, k, prices, dp);
        int ans=-1;

        for(int i=1;i<=k;i++){
            vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
            ans=max(ans, f(0, 1, i, prices, dp));
        }

        return ans;
    }
};

//