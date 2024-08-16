class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n=arr.size();
        int mini=arr[0][0];
        int maxi=arr[0].back();
        int ans=0;

        for(int i=1;i<n;i++){
            ans=max(ans, max(abs(arr[i].back()-mini), abs(maxi-arr[i][0])));

            mini=min(mini, arr[i][0]);
            maxi=max(maxi, arr[i].back());
        }
        
        return ans;
    }
};