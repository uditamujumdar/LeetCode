#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>dist(26, vector<int>(26, 1e9));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j){
                    dist[i][j]=0;
                }
            }
        }
        int m=original.size();
        for(int i=0;i<m;i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            int w=cost[i];
            dist[u][v]=min(dist[u][v], w);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        int n=source.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(dist[u][v]==1e9){
                return -1;
            }
            ans+=dist[u][v];
        }
        return ans;
    }
};