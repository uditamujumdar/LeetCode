#define ll long long
class Solution {
public:
    void dfs(int node, unordered_map<int,bool>&vis, unordered_map<int,vector<int>> &adj){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }

    int countComponents(vector<int>& nums, int thr) {
        int n=nums.size();
        unordered_map<int,vector<int>>adj;

        for(auto i: nums){
            for(auto j=2*i;j<=thr;j+=i){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
       
        unordered_map<int,bool>vis;
        int cnt=0;
        for(auto i: nums){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};