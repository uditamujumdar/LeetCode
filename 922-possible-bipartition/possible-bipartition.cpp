class Solution {
public:
    bool check(int i, vector<int>adj[], vector<int>& color){
        queue<int>q;
        q.push(i);
        color[i]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                if(color[it]==color[node]){
                    return false;
                }
                else if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n];

        for(auto it: dislikes){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }

        vector<int>color(n, -1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!check(i,adj,color))
                return false;
            }
        }

        return true;
    }
};