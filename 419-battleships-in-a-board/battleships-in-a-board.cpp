class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& board){
        int m=board.size(); 
        int n=board[0].size();
        vis[r][c]=1;
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr<m && nc<n && nr>=0 && nc>=0 && !vis[nr][nc] && board[nr][nc]=='X'){
                dfs(nr, nc, vis, board);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(); 
        int n=board[0].size();
        int ans=0;

        vector<vector<int>>vis(m ,vector<int>(n, 0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis[i][j] && board[i][j] == 'X'){
                    dfs(i, j, vis, board);
                    ans++;
                }
            }
        }
        return ans;
    }
};