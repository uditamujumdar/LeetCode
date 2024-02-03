class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int maxi = 0;
            for (int j = i; j < k + i && j < n; j++) {
                maxi= max(maxi, arr[j]);
                int curr = maxi * (j - i + 1) + dp[j + 1];
                dp[i] = max(dp[i], curr);
            }
        }
        return dp[0];
    }
};