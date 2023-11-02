class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>>ans;
        map<int, vector<int>>mp;

        for(int i=0;i<gs.size();i++){
            mp[gs[i]].push_back(i);

            if(mp[gs[i]].size()==gs[i]){
                ans.push_back(mp[gs[i]]);
                mp[gs[i]].clear();
            }
        }

        return ans;    
    }
};