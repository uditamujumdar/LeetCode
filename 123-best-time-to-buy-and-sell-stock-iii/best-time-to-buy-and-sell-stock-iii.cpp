class Solution {
public:
    int f(int ind, int buy, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind>=prices.size() || cnt<=0){
            return 0;
        }
        if(dp[ind][buy][cnt]!=-1){
            return dp[ind][buy][cnt];
        }

        if(buy==1){
            int a=-prices[ind]+f(ind+1, 1-buy, cnt, prices, dp);
            int b=f(ind+1, buy, cnt, prices, dp);

            return dp[ind][buy][cnt]=max(a, b);   
        }

        else{
            int a=prices[ind]+f(ind+1, 1-buy, cnt-1, prices, dp);
            int b=f(ind+1, buy, cnt, prices, dp);

            return dp[ind][buy][cnt]=max(a, b);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //ind,buy,count

        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, 2, prices, dp);
    }
};