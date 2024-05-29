class Solution {
public: 
    long long f(int ind, int flag, vector<int>& nums, vector<vector<long long>>&dp){
        if(ind<0){
            return 0;
        }
        if(dp[ind][flag]!=-1){
            return dp[ind][flag];
        }

        long long notpick=0+f(ind-1, flag, nums, dp);
        long long pick=0;
        if(flag==0){
            pick=nums[ind]+f(ind-1, 1, nums, dp);
        }
        else{
            pick=-nums[ind]+f(ind-1, 0, nums, dp);
        }

        return dp[ind][flag]=max(pick, notpick);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n+1, vector<long long>(2, -1));
        return f(n-1, 0, nums, dp);
    }
};