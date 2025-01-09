class Solution {
public:
    int bfs(int node, vector<int>&vis, vector<int>adj[]){
        vis[node]=1;
        queue<int>q;
        q.push(node);
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    cnt++;
                    q.push(it);
                }
            }
        }
        return cnt;
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>adj[n];
        vector<int>indeg(n,0);

        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
                indeg[edges[i]]++;
            }
        }

        queue<int>q;
        vector<int>topo;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(topo.size()==n){
            return -1;
        }
        vector<int>vis(n, 0);
        for(auto it: topo){
            vis[it]=1;
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                maxi=max(maxi, bfs(i,vis,adj));
            }
        }
        return maxi+1;
    }
};
//\U0001f614\U0001f614