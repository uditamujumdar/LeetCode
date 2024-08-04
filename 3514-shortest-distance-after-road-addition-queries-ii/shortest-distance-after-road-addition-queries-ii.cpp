class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& que) {
        vector<int>ans;
        vector<int>dist(n, 0);
        set<int>valid;
        for(int i=0;i<n;i++){
            valid.insert(i);
        }

        for(auto it: que){
            int start=it[0];
            int end=it[1];

            auto lb=valid.lower_bound(start+1);
            auto ub=valid.lower_bound(end);

            valid.erase(lb,ub);

            ans.push_back(valid.size()-1);
        }
        return ans;
    }
};