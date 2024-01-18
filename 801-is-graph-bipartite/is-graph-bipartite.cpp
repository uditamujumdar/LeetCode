class Solution {
public:
    bool bfs(int i, vector<int>adj[], vector<int>& color){
        queue<int>q;
        q.push(i);
        color[i]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it: adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }

                if(color[it]==color[node]){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                // adj[j].push_back(graph[i][j]);
            }
        }

        vector<int>color(n, -1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,adj,color)){
                    return false;
                }
            }
        }
        return true;
    }
};