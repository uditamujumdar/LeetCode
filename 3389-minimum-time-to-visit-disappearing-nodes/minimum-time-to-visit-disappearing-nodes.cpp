class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>>adj[n];
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int>dist(n, 1e9);
        dist[0]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        //time,node
        pq.push({0,0});

        //since the graph may contain multiple edges
        vector<int>vis(n, 0);

        while(!pq.empty()){
            int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            
            for(auto it: adj[node]){
                int adjnode=it.first;
                int w=it.second;
                if(w+t<dist[adjnode] && w+t<disappear[adjnode]){
                    dist[adjnode]=w+t;
                    pq.push({w+t, adjnode});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }

        return dist;
    }
};