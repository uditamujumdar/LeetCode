class Solution {
public:    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        queue<pair<int,pair<int,int>>>q;
        q.push({health-grid[0][0], {0,0}});
        vis[0][0]=health-grid[0][0];
        
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int he=q.front().first;
            q.pop();
            
            if(r==n-1 && c==m-1 && he>=1){
                return true;
            }
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                int nhealth=he;
                
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(grid[nr][nc]==1){
                        nhealth--;
                    }
                    if(nhealth>0 && vis[nr][nc]<nhealth){
                        vis[nr][nc]=nhealth;
                        q.push({nhealth,{nr,nc}});
                    }
                }
            }
        }
        return false;
    }
};