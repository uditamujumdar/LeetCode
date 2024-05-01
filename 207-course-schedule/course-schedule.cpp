class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        for(auto it: pre){
            adj[it[1]].push_back(it[0]);
        }

        vector<int>indeg(n, 0);
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indeg[it]++;
            }
        }
        vector<int>topo;
        queue<int>q;
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

        return topo.size()==n;
    }
};