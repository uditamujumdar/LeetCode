class Solution {
public:
    bool f(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(sum==0){
            return true;
        }
        if(sum<0 || ind>=nums.size()){
            return false;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int pick=f(ind+1, sum-nums[ind], nums, dp);
        int notpick=f(ind+1, sum, nums, dp);

        return dp[ind][sum]=pick|notpick;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(), nums.end(), 0);
        if(total&1){
            return false;
        }
        int sum=total/2;

        vector<vector<int>>dp(n, vector<int>(sum+1, -1));

        return f(0, sum, nums, dp);
    }
};