class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int ind, vector<vector<int>>& vis){
        int n=board.size();
        int m=board[0].size();
        int w=word.size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        if(ind==w-1){
            return true;
        }   
        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && 
                board[nrow][ncol]==word[ind+1]){
                if(dfs(board,word,nrow,ncol,ind+1,vis)){
                    return true;
                }
            }
        }
        vis[row][col]=0;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j]==word[0]) {
                    if(dfs(board, word, i, j, 0, vis))
                    return true;
                }
            }
        }

        return false;
    }
};