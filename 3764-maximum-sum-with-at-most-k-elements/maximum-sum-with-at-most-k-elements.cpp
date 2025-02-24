class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& lim, int k) {
        int n=grid.size();
        int m=grid[0].size();
        if(k==0){
            return k;
        }
        vector<int>temp;

        for(int i=0;i<n;i++){
            sort(grid[i].rbegin(), grid[i].rend());
            for(int j=0;j<lim[i];j++){
                temp.push_back(grid[i][j]);
            }
        }

        sort(temp.rbegin(), temp.rend());
        long long sum=0;

        for(int i=0;i<k;i++){
            sum+=temp[i];
        }
        return sum;
    }
};