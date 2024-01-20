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

        vector<int>adjrev[n];
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                adjrev[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int>q;
        vector<int>safe;

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);

            for(auto it:adjrev[node]){
                indeg[it]--;

                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};