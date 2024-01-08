class Solution {
public:
    int solve(int tar, vector<int>& nums, vector<int>& dp){
        // if(i==0){
        //     if(tar%nums[0]==0){
        //         return 1;
        //     }
        //     return 0;
        // }

        // if(dp[i][tar]!=-1){
        //     return dp[i][tar];
        // }

        // int take=0;
        // int nottake=solve(i-1, tar, nums, dp);
        // if(nums[i]<=tar){
        //     take=solve(i, tar-nums[i], nums, dp);
        // }
        
        // return dp[i][tar]=nottake+take;
        if(tar==0){
            return 1;
        }
        if(dp[tar]!=-1){
            return dp[tar];
        }
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=tar){
                ans+=solve(tar-nums[i], nums, dp);
            }
        }
        return dp[tar]=ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        // return solve(n-1, target, nums, dp);

        vector<int>dp(target+1, -1);
        return solve(target, nums, dp);
    }
};