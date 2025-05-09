class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& en) {
        int n=maze.size();
        int m=maze[0].size();

        //dist, {row, col}
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0, {en[0], en[1]}});

        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};

        vector<vector<bool>>vis(n, vector<bool>(m, false));
        vis[en[0]][en[1]]=1;

        while(!pq.empty()){
            int dis=pq.front().first;
            int r=pq.front().second.first;
            int c=pq.front().second.second;
            pq.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]=='.' &&!vis[nr][nc]){
                    pq.push({dis+1, {nr, nc}});
                    vis[nr][nc]=true;
                    
                    if(nr==0 || nc==0 || nr==n-1 || nc==m-1){
                        return dis+1;
                    }
                }
            }
        }
        return -1;
    }
};