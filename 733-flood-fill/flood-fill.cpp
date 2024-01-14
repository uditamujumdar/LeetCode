class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&img,int color,int ini)
    {
        ans[row][col]=color;
        int n=img.size();
        int m=img[0].size();

        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

        if(nrow>=0&&nrow<n &&ncol>=0&&ncol<m&& ans[nrow][ncol]!=color && img[nrow][ncol]==ini)
        {
            dfs(nrow, ncol, ans, img, color, ini);
        }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int ini=image[sr][sc];

        dfs(sr,sc,ans,image,color,ini);

        return ans;
    }
};