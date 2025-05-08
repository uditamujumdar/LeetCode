class Solution {
public:
    int minTimeToReach(vector<vector<int>>& move) {
        int n=move.size();
        int m=move[0].size();

        vector<vector<int>>dist(n, vector<int>(m, 0));
        vector<vector<bool>>vis(n, vector<bool>(m, false));

        priority_queue<pair<int,pair<int,pair<int,int>>>, vector<pair<int,pair<int,pair<int,int>>>>, greater<>>pq;
        
        pq.push({0, {0, {0,0}}});

        dist[0][0]=0;
        vis[0][0]=1;
        
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};

        while(!pq.empty()){
            int t=pq.top().first;
            int moves=pq.top().second.first;
            int r=pq.top().second.second.first;
            int c=pq.top().second.second.second;
            pq.pop();

            if(r==n-1 && c==m-1){
                break;
            }

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    int nt=max(t, move[nr][nc]) + (moves%2==0 ? 1 : 2);
                    vis[nr][nc]=1;
                    dist[nr][nc]=nt;
                    pq.push({nt, {moves+1, {nr, nc}}});
                }
            }
        }

        return dist[n-1][m-1];
    }
};