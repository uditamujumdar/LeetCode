class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it: fl){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        //here stops is the main character
        q.push({0, {src, 0}});

        vector<int>dist(n, INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();

            if(stops>k){
                continue;
            }

            for(auto it: adj[node]){
                int adjnode=it.first;
                int w=it.second;
                if(cost+w<dist[adjnode] && stops<=k){
                    dist[adjnode]=cost+w;
                    q.push({stops+1, {adjnode, cost+w}});
                }
            }
        }

        if(dist[dst]==INT_MAX)return -1;

        return dist[dst];
    }
};