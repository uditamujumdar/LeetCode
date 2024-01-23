class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>>dist(n+1, vector<int>(n+1, 1e9));

        for(int i=1;i<n;i++){
            dist[i][i+1]=1;
            dist[i+1][i]=1;
        }
        for(int i=1;i<=n;i++){
            dist[i][i]=0;
        }
        if(x!=y){
            dist[x][y]=1;
            dist[y][x]=1;
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        vector<int>ans(n);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j]!=1e9 && dist[i][j]!=0){
                    ans[dist[i][j]-1]++;
                }
            }
        }
        return ans;
    }
};