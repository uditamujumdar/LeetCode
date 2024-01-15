class Solution {
public:
    void dfs(int node,vector<int>& vis, vector<int>adj[], int& vert, int& edge){
        vis[node]=1;
        vert++;
        for(auto it: adj[node]){
            edge++;
            if(!vis[it]){
                dfs(it, vis, adj,vert,edge);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        int ans=0;

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>vis(n, 0);

        for(int i=0;i<n;i++){
            int vert=0, edge=0;
            if(!vis[i]){
                dfs(i,vis,adj,vert,edge);
                if(vert*(vert-1)==edge) ans++;
            }
        }
        return ans;
    }
};