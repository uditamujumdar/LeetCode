class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {
        vector<int>adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        vector<int>vis(n, 0);

        q.push(0);
        vis[0]=1;
        set<int>st(rest.begin(),rest.end());

        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            vis[node]=1;
            q.pop();
            cnt++;

            for(auto it: adj[node]){
                if(!vis[it] && st.find(it)==st.end()){
                    q.push(it);
                }
            }
        }
        return cnt;
    }
};