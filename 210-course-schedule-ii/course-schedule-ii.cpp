class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<int>adj[n];
        for(auto it:prereq){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>indeg(n,0);

        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
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
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        reverse(topo.begin(),topo.end());
        if(topo.size()==n){
           return topo;
        }
        return {};
    }
};