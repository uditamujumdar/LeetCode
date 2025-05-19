class Solution {
public:
    int f(int ind, vector<int>&nums, vector<int>&dp){
        if(ind==nums.size()-1){
            return nums[ind];
        }
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int notpick=f(ind+1, nums, dp);
        int pick=nums[ind]+f(ind+2, nums, dp);

        return dp[ind]=max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>v=nums;
        v.pop_back();
        if(n==1){
            return nums[0];
        }

        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);

        int a=f(1, nums, dp1);
        int b=f(0, v, dp2);

        return max(a, b);
    }
};