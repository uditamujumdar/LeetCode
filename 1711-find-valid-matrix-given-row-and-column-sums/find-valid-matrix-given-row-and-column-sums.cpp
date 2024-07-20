class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r=rowSum.size();
        int c=colSum.size();

        vector<vector<int>>v(r, vector<int>(c, 0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(rowSum[i]==0 || colSum[j]==0){
                    v[i][j]=0;
                }
                else{
                    v[i][j]=min(rowSum[i], colSum[j]);
                    rowSum[i]-=v[i][j];
                    colSum[j]-=v[i][j];
                }
            }
        }
        return v;
    }
};