class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int Len) {
        int n=tiles.size();
        sort(tiles.begin(), tiles.end());
        int i=0, j=0, ans=0, x=0;

        while(i<n && j<n){
            if(tiles[i][0]+Len > tiles[j][1]){
                x+=(tiles[j][1]-tiles[j][0]+1);
                ans=max(ans, x);
                j++;
            }
            else{
                ans=max(ans, x+max(0, tiles[i][0]+Len-tiles[j][0]));
                x-=(tiles[i][1]-tiles[i][0]+1);
                i++;
            }
        }
        return ans;        
    }
};