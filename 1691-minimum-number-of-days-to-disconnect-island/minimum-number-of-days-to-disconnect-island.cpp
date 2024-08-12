class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,vis,grid);
                vis[nr][nc]=1;
            }
        }
    }
    int count(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=count(grid);

        if(cnt>1 || cnt<1){
            return 0;
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        cnt=count(grid);
                        grid[i][j]=1;

                        if(cnt<1 || cnt>1){
                            return 1;
                        }
                    }
                }
            }
        }

        return 2;
    }
};