class Solution {
public:
    int f(int tar, vector<int>&nums, vector<int>&dp){
        // if(ind>=nums.size()||tar<0){
        //     return 0;
        // }
        if(tar==0){
            return 1;
        }
        if(dp[tar]!=-1){
            return dp[tar];
        }
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(tar-nums[i]>=0){
                ans+=f(tar-nums[i], nums, dp);
            }
        }

        return dp[tar]=ans;
    }
    
    int combinationSum4(vector<int>& nums, int tar) {
        int n=nums.size();

        vector<int>dp(tar+1, -1);

        return f(tar, nums, dp);
    }
};