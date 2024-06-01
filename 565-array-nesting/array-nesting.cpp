class Solution {
public:
    void dfs(int node, vector<int>&nums, vector<bool>& vis, int& cnt){
        if(vis[node]==1){
            return;
        }
        vis[node]=1;
        cnt++;
        return dfs(nums[node], nums, vis, cnt);
    }

    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        vector<bool>vis(n, 0);
        
        for(int i=0;i<n;i++){
            int cnt=0;
            dfs(i, nums, vis, cnt);
            ans=max(ans, cnt);
        }
        return ans;
    }
};
