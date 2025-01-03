class Solution {
public:
    void f(int node, vector<int>&vis, vector<int>adj[], vector<int>&res){
        vis[node]=1;

        for(auto it: adj[node]){
            if(!vis[it] && !res[it]){
                f(it, vis, adj, res);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>res(n, 0);
        for(auto it: restricted){
            res[it]=1;
        }
        vector<int>vis(n, 0);

        f(0,vis,adj,res);

        int ans=0;
        for(auto it: vis){
            if(it!=0){
                ans++;
            }
        }
        return ans;
    }
};