class Solution {
public:
    int f(bool alice, int ind, int m, vector<int>& piles, vector<vector<vector<int>>>&dp){
        if(ind>=piles.size()){
            return 0;
        }
        if(dp[alice][ind][m]!=-1){
            return dp[alice][ind][m];
        }
        int res=alice?0:INT_MAX;
        int tot=0;

        for(int i=1;i<=2*m;i++){
            if(ind+i>piles.size())break;
            
            tot+=piles[ind+i-1];

            if(alice){
                res=max(res, tot+f(!alice, ind+i, max(m,i), piles, dp));
            }
            else{
                res=min(res, f(!alice, ind+i, max(m,i), piles, dp));
            }
        }

        return dp[alice][ind][m]=res;
    }

    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n, vector<int>(n+1,-1)));

        return f(true,0,1,piles,dp);
    }
};