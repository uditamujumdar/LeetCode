#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>>adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<ll>dist(n, LONG_MAX);
        vector<ll>ways(n,0);
        dist[0]=0;
        ways[0]=1;

        //dist,node
        priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            ll d=pq.top().first;
            ll node=pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                ll adjnode=it.first;
                ll edwt=it.second;

                //first time arriving with this distance
                if(d+edwt<dist[adjnode]){
                    dist[adjnode]=d+edwt;
                    pq.push({d+edwt, adjnode});
                    ways[adjnode]=ways[node];
                }

                //already arrived
                else if(d+edwt==dist[adjnode]){
                    ways[adjnode]+=ways[node]%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};