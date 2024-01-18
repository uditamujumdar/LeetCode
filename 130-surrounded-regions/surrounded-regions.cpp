class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& v){
        vis[r][c]=1;
        int n=v.size();
        int m=v[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] &&v[nrow][ncol]=='O')
            {
                dfs(nrow, ncol, vis, v);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(!vis[i][j] && board[i][j]=='O'){
                        dfs(i,j,vis,board);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};