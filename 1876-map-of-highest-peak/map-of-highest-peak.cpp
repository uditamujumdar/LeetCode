class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();

        vector<vector<int>>ans(n, vector<int>(m, -1));
        queue<pair<int,int>>q;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int height=ans[row][col];

            for(int i=0;i<4;i++){
                int nr=row+drow[i];
                int nc=col+dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc]==-1){
                    ans[nr][nc]=height+1;
                    q.push({nr,nc});
                }
            }
        }

        return ans;
    }
};