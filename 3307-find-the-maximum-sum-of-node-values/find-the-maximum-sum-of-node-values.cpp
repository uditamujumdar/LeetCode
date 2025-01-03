class Solution {
public:
    long long f(int i, int c, vector<int>&nums, int k, vector<vector<long long>>&dp){
        if(i>=nums.size()){
            return c?INT_MIN:0;
        }
        if(dp[i][c]!=-1){
            return dp[i][c];
        }
        long long x=nums[i];

        return dp[i][c]=max(x+f(i+1,c,nums,k,dp), (x^k)+f(i+1,!c,nums,k,dp));
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<long long>>dp(n, vector<long long>(2,-1));

        return f(0,0,nums,k,dp);
    }
};