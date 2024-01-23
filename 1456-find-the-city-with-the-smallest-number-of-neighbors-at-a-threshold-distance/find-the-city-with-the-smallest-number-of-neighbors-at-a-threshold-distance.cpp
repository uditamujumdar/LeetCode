class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));

        for(auto it: edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }

        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX||dist[k][j]==INT_MAX){
                        continue;
                    }
                    else{
                        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        int city=n;
        int num=-1;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=thresh){
                    cnt++;
                }
            }

            if(cnt<=city){
                city=cnt;
                num=i;
            }
        }

        return num;
    }
};