class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& hei) {
        int n=hei.size();
        int m=hei[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        //effort, row, col
        pq.push({0, {0,0}});

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        dist[0][0]=0;

        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};

        while(!pq.empty()){
            int eff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int neff=max(abs(hei[r][c]-hei[nr][nc]), eff);
                    if(neff < dist[nr][nc]){
                        dist[nr][nc]=neff;
                        pq.push({neff, {nr, nc}});
                    }
                }
            }
        }

        if(dist[n-1][m-1]==INT_MAX){
            return 0;
        }

        return dist[n-1][m-1];
    }
};