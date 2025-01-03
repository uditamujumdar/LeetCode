class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n+1];
        vector<int>indeg(n+1,0);

        for(auto it: relations){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        int ans=0;
        vector<int>wait(n+1);
        queue<int>q;

        for(int i=1;i<=n;i++){
            if(indeg[i]==0){
                q.push(i);
                wait[i]=time[i-1];
                ans=max(ans, wait[i]);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                indeg[it]--;
                wait[it]=max(wait[it], time[it-1]+wait[node]);
                ans=max(ans, wait[it]);

                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};