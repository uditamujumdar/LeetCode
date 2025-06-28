class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({1, {0,0}});

        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        dist[0][0]=1;


        while(!q.empty()){
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            if(r==n-1 && c==n-1){
                return d;
            }

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=r+i;
                    int nc=c+j;

                    if(nr>=0 && nc>=0 && nr<n && nc<n && d+1<dist[nr][nc] && grid[nr][nc]==0){
                        dist[nr][nc]=d+1;
                        q.push({d+1,{nr,nc}});
                    }
                }
            }
        }

        if(dist[n-1][n-1]==INT_MAX){
            return -1;
        }

        return dist[n-1][n-1];
    }
};