class Solution {
public:
    int f(int r, int c, vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        int curr=grid[r][c];
        grid[r][c]=0;
        int maxi=curr;

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]!=0){
                maxi=max(maxi, curr+f(nr,nc,grid));
            }
        }
        grid[r][c]=curr;
        return maxi;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0)
                maxi=max(maxi, f(i,j,grid));
            }
        }
        return maxi;
    }
};