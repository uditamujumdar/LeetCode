class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>vis(n, 0);
        vector<int>indeg(n,0);
        vector<int>ans;

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                ans.push_back(i);
            }
        }

        for(auto it: ans){
            dfs(it, vis, adj);
        }

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};