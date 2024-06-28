class Solution {
public:
    int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& inform) {
        if(n==1){
            return 0;
        }
        vector<int>adj[n];

        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }

        vector<int>sum(n,0);
        queue<int>q;
        q.push(head);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it: adj[node]){
                sum[it]=sum[node]+inform[node];
                q.push(it);
            }
        }

        int ans=-1;
        for(auto it: sum){
            ans=max(ans, it);
        }

        return ans;
    }
};