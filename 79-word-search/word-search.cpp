class Solution {
public:
    bool f(int i, int j, vector<vector<char>>& board, int k, string& word){
        if(k==word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[k]){
            return false;
        }
        char ch=board[i][j];
        board[i][j]='\0';

        if(f(i+1,j,board,k+1,word) || f(i-1,j,board,k+1,word) || f(i,j+1,board,k+1,word) || f(i,j-1,board,k+1,word)){
            return true;
        }

        board[i][j]=ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(f(i, j, board, 0, word)){
                    return true;
                }
            }
        }

        return false;
    }
};