class Solution {
public:
    int solve(int i,int sum, vector<int>& nums,vector<vector<int>>&dp){
        if(i>=nums.size()){
            if(sum==0){
                return 0;
            }
            return INT_MIN;
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }

        int pick=nums[i]+solve(i+1,(sum+nums[i])%3,nums,dp);

        int notpick=solve(i+1,sum,nums,dp);

        return dp[i][sum]=max(pick,notpick);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return solve(0, sum, nums, dp);
    }
};