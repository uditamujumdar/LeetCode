class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int>outdeg(n, 0);
        vector<int>adjrev[n];
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                adjrev[it].push_back(i);
                outdeg[i]++;
            }
        }
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adjrev[node]){
                outdeg[it]--;
                if(outdeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};