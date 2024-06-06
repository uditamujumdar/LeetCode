class Solution {
public:
    int f(int ind, vector<vector<int>>&eve, int k, vector<vector<int>>&dp,vector<int>&v){
        if(ind>=eve.size() || k==0){
            return 0;
        }
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        int i=upper_bound(v.begin(), v.end(),eve[ind][1])-v.begin();
        int notpick=f(ind+1,eve,k,dp,v);
        int pick=eve[ind][2]+f(i,eve,k-1,dp,v);
        
        return dp[ind][k]=max(pick,notpick);
    }

    int maxValue(vector<vector<int>>& eve, int k) {
        int n=eve.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        sort(eve.begin(), eve.end());

        vector<int>v;
        for(auto it: eve){
            v.push_back(it[0]);
        }
        return f(0,eve,k,dp,v);
    }
};