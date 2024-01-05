class Solution {
public:
    int helper(int idx, vector<int>& arr,vector<vector<int>>& dp, int prev) {
        int n = arr.size();
        if (idx == n) return 0;
        if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];

        int nottake = helper(idx + 1, arr, dp, prev);
        int take = 0;

        if (prev == -1 || arr[idx] > arr[prev]) {
            take = helper(idx + 1, arr, dp, idx) + 1;
        }

        return dp[idx][prev + 1] = max(nottake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return helper(0, nums, dp, -1);
    }
};