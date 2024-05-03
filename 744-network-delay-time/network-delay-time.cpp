class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it: times){
            int u=it[0]; 
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>tim(n+1, 1e9);
        tim[k]=0;
        //{time,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        tim[k]=0;

        while(!pq.empty()){
            int node=pq.top().second;
            int t=pq.top().first;
            pq.pop();

            for(auto it:adj[node]){
                int adjnode=it.first;
                int w=it.second;
                if(t+w<tim[adjnode]){
                    tim[adjnode]=w+t;
                    pq.push({t+w,adjnode});
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(tim[i]==1e9){
                return -1;
            }
        }

        sort(tim.begin(), tim.end());
        return tim[n-1];
    }
};