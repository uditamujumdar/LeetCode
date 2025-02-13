class Solution {
public:
    int f(int ind, int sum, vector<int>& nums, vector<vector<int>>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int notpick=f(ind+1, sum, nums, dp);
        int pick=nums[ind]+f(ind+2, sum+nums[ind], nums, dp);

        return dp[ind][sum]=max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));

        return f(0,0,nums,dp);
    }
};