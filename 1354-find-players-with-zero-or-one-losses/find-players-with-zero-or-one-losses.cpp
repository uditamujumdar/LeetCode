class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        int m=matches[0].size();

        map<int, int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[matches[i][j]]=0;
            }
        }

        for(int i=0;i<n;i++){
            mp[matches[i][1]]++;
        }

        vector<vector<int>>ans;
        vector<int>v;

        for(auto it: mp){
            if(it.second==0){
                v.push_back(it.first);
            }
        }
        ans.push_back(v);
        v.clear();
        
        for(auto it: mp){
            if(it.second==1){
                v.push_back(it.first);
            }
        }
        ans.push_back(v);

        return ans;
    }
};