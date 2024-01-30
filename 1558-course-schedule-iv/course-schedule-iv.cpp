class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        vector<bool>ans;
        for(auto it:prereq){
            int u=it[0];
            int v=it[1];
            mat[u][v]=1;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            if(mat[u][v]!=1e9){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};