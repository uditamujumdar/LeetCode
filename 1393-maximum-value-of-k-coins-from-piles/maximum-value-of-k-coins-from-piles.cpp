class Solution {
public:
    int f(int ind, int k, vector<vector<int>>&v, vector<vector<int>>&dp){
        if(ind>=v.size()){
            return 0;
        }
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        int s=v[ind].size();
        int maxi=min(k, s);

        int maxsum=f(ind+1,k,v,dp);
        int pick=0;

        for(int i=0;i<maxi;i++){
            int val=v[ind][i];
            pick+=val;

            int next=f(ind+1, k-i-1, v, dp);
            maxsum=max(maxsum, pick+next);
        }

        return dp[ind][k]=maxsum;	
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n, vector<int>(k+1,-1));
        return f(0,k,piles,dp);
    }
};