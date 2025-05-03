class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<pair<int,int>>adj[n];
        //red=0, blue=1
        for(auto it: red){
            int a=it[0];
            int b=it[1];
            adj[a].push_back({b, 1});
        }
        for(auto it: blue){
            int a=it[0];
            int b=it[1];
            adj[a].push_back({b, 2});
        }

        queue<pair<int,int>>q;
        q.push({0,0});

        vector<vector<int>>dist(n, vector<int>(3, 1e9));
        dist[0][0]=0;

        while(!q.empty()){
            int node=q.front().first;
            int col=q.front().second;
            q.pop();        

            for(auto it: adj[node]){
                if(col==0 || it.second!=col){
                    if(dist[it.first][it.second]==1e9){
                        dist[it.first][it.second] = dist[node][col] + 1;
                        q.push({it.first, it.second});
                    }
                }
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        }
        vector<int>ans(n, 0);

        for(int i=1;i<n;i++){
            ans[i]=min(dist[i][1], dist[i][2]);
            if(ans[i]==1e9){
                ans[i]=-1;
            }
        }

        return ans;
    }
};