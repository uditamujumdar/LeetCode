class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size();

        for(int i=0 ; i<n; i++){
            if(grid[i][0] == 0){
                for(int j=0 ; j<m; j++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        for(int j=0 ; j<m; j++){
            int countzero=0, countone=0; 
            for(int i=0 ; i<n; i++){
                if(grid[i][j] == 0){
                    countzero++;
                }
                else{
                    countone++;
                }
            }

            if(countzero > countone){
                for(int i=0 ; i<n; i++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int rowans = 0;
            for (int j = 0; j < m; j++) {
                rowans += pow(2, m - j - 1) * grid[i][j];
            }
            ans += rowans;
        }

        return ans;
    }
};