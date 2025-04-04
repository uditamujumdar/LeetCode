class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, -1));
        queue<vector<int>>q;
        q.push({0,0,0,k});

        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int len=q.front()[2];
            int obs=q.front()[3];
            q.pop();

            if(i<0 || j<0 || i>=n || j>=m){
                continue;
            }

            if(i==n-1 && j==m-1){
                return len;
            }

            if(grid[i][j]==1){
                if(obs>0){
                    obs--;
                }
                else{
                    continue;
                }
            }

            if(vis[i][j]!=-1 && vis[i][j]>=obs){
                continue;
            }
            vis[i][j]=obs;
            q.push({i+1, j, len+1, obs});
            q.push({i-1, j, len+1, obs});
            q.push({i, j+1, len+1, obs});
            q.push({i, j-1, len+1, obs});
        }

        return -1;
    }
};