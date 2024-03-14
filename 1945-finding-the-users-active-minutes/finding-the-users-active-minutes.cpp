class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>>mp;
        vector<int>v(k,0);
        for(auto it: logs){
            mp[it[0]].insert(it[1]);
        } 

        for(auto it: mp){
            v[it.second.size()-1]++;
        }

        return v;
    }
};