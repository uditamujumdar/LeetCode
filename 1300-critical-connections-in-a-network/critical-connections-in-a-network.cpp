class Solution {
private:
    int timer=1;
    void dfs(int node,int par,vector<int>&vis,vector<int>adj[],int tin[],int low[],vector<vector<int>>&br){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;

        for(auto it: adj[node]){
            if(it==par)continue;
            if(vis[it]==0){
                dfs(it, node, vis, adj, tin, low, br);
                low[node]=min(low[node], low[it]);
                if(low[it]>tin[node]){
                    br.push_back({it, node});
                }
            }

            else{
                low[node]=min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<int>adj[n];
        for(auto it: conn){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};