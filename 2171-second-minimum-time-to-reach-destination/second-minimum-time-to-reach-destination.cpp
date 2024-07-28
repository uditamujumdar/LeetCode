class Solution {
public:
    int f(int steps, int time, int change){
        int ans=0;
        for(int i=0;i<steps;i++){
            int gr=ans/change;
            if(gr&1){
                ans=change*(gr+1);
            }
            ans+=time;
        }
        return ans;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dist(n+1, 1e9), dist2(n+1, 1e9);
        queue<pair<int,int>>q;
        q.push({0,1});
        dist[1]=0;

        while(!q.empty()){
            int t=q.front().first;
            int node=q.front().second;
            q.pop();

            for(auto it: adj[node]){
                int newt=t+1;
                if(newt<dist[it]){
                    dist2[it]=dist[it];
                    dist[it]=newt;
                    q.push({newt,it});
                }
                else if(newt>dist[it] && newt<dist2[it]){
                    dist2[it]=newt;
                    q.push({newt,it});
                }
            }
        }
        int steps=dist2[n];
        if(steps==1e9){
            return -1;
        }
        return f(steps, time, change);
    }
};