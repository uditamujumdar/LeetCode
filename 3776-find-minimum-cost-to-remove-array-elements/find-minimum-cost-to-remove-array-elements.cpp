class Solution {
public:
    int f(int ind, int prev, vector<int>&nums, vector<vector<int>>&dp){
        if(ind>=nums.size()){
            return nums[prev];
        }
        if(ind==nums.size()-1){
            return max(nums.back(), nums[prev]);
        }
        if(dp[prev][ind]!=-1){
            return dp[prev][ind];
        }

        int a=max(nums[prev], nums[ind])+f(ind+2, ind+1, nums, dp);

        int b=max(nums[ind], nums[ind+1])+f(ind+2, prev, nums, dp);

        int c=max(nums[prev], nums[ind+1])+f(ind+2, ind, nums, dp);

        return dp[prev][ind]=min({a,b,c});
    }

    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return f(1,0,nums,dp);
    }
};