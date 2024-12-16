class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            int z=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0){
                    z++;
                }
                else{
                    break;
                }
            }
            v[i]=z;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int req=n-1-i;
            int row=-1;
            for(int j=i;j<n;j++){
                if(v[j]>=req){
                    row=j;
                    break;
                }
            }
            if(row==-1){
                return -1;
            }
            for(int j=row;j>i;j--){
                swap(v[j], v[j-1]);
                ans++;
            }
        }
        return ans;
    }
};