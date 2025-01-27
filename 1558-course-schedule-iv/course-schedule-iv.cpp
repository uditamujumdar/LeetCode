class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>adj[n];
        for(auto it: prereq){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>indeg(n, 0);
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indeg[it]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        vector<vector<bool>>check(n, vector<bool>(n, false));
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }

                check[node][it]=1;
                //a is a prereq of b, and b is a prereq of c, then a is a prereq of c.
                //so check for prereqs of 'node', they'll also be prereqs of 'it' now
                for(int i=0;i<n;i++){
                    if(check[i][node]==true){
                        check[i][it]=true;
                    }
                }
            }
        }

        for(auto it: queries){
            ans.push_back(check[it[0]][it[1]]);
        }

        return ans;
    }
};