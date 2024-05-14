class Solution {
public:
    int f(int i, int j, vector<int>& u, vector<int>& v, vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(u[i]==v[j]){
            return dp[i][j]=1+f(i-1,j-1,u,v,dp);
        }
        return 0;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));

        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi, f(i,j,nums1,nums2,dp));
            }
        }
        return maxi;
    }
};