class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        vector<double>prob(n,0);
        vector<vector<pair<int,double>>>adj(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double w=succ[i];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        //{prob,node}
        priority_queue<pair<double,int>>pq;
        pq.push({1,start});
        prob[start]=1;

        while(!pq.empty()){
            double p=pq.top().first;
            int node=pq.top().second;
            pq.pop();
           
            for(auto it: adj[node]){
                int adjnode=it.first;
                double p1=it.second;

                if(p1*p>prob[adjnode]){
                    prob[adjnode]=p1*p;
                    pq.push({prob[adjnode], adjnode});
                }
            }
        }

        return prob[end];
    }
};