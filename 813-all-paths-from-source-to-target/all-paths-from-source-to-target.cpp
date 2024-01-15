class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<vector<int>>&ans,vector<int>output,int target){
        if(node==target){
            if(output.size()!=0){
                output.push_back(target);
                ans.push_back(output);
            }
            return;
        }
        for(auto it:adj[node]){
            output.push_back(node);
            dfs(it,adj,ans,output,target);
            output.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>output;
        int n=graph.size();
        vector<int>adj[n];

        for(int i=0;i<n;i++){
            if(i==n-1){
                adj[i].push_back(-1);
            }
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        dfs(0,adj,ans,output,n-1);

        return ans;

        
    }
};