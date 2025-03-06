class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(2);
        map<int, int>mp;
        for(int i=1;i<=grid.size()*grid.size();i++){
            mp[i]=0;
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                mp[grid[i][j]]++;
            }
        }
        
        for(auto i:mp){
            if(i.second==2){
                ans[0]=i.first;
            }
            if(i.second==0){
                ans[1]=i.first;
            }
        }
        
        return ans;
    }
};