class Solution {
public:
    int minTimeToReach(vector<vector<int>>& move) {
        int n=move.size();
        int m=move[0].size();

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        //time, {row, col}
        pq.push({0, {0,0}});

        dist[0][0]=0;
        
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};

        while(!pq.empty()){
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int nt=max(t+1, move[nr][nc]+1);
                    if(nt<dist[nr][nc]){
                        dist[nr][nc]=nt;
                        pq.push({nt, {nr, nc}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};