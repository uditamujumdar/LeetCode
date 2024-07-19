class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();

        vector<int>row, col;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=0;j<m;j++){
                mini=min(mini, mat[i][j]);
            }
            row.push_back(mini);
        }

        for(int i=0;i<m;i++){
            int maxi=-1;
            for(int j=0;j<n;j++){
                maxi=max(maxi, mat[j][i]);
            }
            col.push_back(maxi);
        }
        
        for(int i=0;i<row.size();i++){
            if(find(col.begin(), col.end(),row[i])!=col.end()){
                ans.push_back(row[i]);
            }
        }
        return ans;
    }
};
