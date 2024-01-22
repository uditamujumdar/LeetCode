class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,
                        greater<pair<int, pair<int,int>>>>pq;
        
        
        vector<vector<int>>dist(n, vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        while(!pq.empty()){
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            
            if(r==n-1&&c==m-1){
                return diff;
            }
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0&&nc>=0&&nr<n&&nc<m){
                    int neweffort=max(abs(heights[nr][nc]-heights[r][c]), diff);
                    
                    if(neweffort<dist[nr][nc]){
                        dist[nr][nc]=neweffort;
                        pq.push({neweffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};