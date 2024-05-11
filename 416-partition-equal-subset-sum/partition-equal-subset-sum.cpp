class Solution {
public:
    bool f(int ind, vector<int>& nums, int tar, vector<vector<int>>& dp){
        if(tar==0){
            return true;
        }
        if(ind==0){
            return nums[0]==tar;
        }
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }

        bool nottake=f(ind-1, nums, tar, dp);
        bool take=false;
        if(nums[ind]<=tar){
            take=f(ind-1, nums, tar-nums[ind], dp);
        }

        return dp[ind][tar]=take|nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(), nums.end(), 0);
        if(total&1){
            return false;
        }
        vector<vector<int>>dp(n, vector<int>(total/2+1, -1));
        return f(n-1, nums, total/2, dp);
    }
};