class Solution {
public:
    static bool comparator(pair<int, int>& a, pair<int, int>& b){
        return (a.second>b.second);
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>ans;
        pair<int, int>p;
        vector<pair<int, int>>v;

        int n=names.size();

        for(int i=0;i<n;i++){
            v.push_back(make_pair(i, heights[i]));
        }
    
        sort(v.begin(), v.end(), comparator);

        for(int i=0;i<n;i++){
            ans.push_back(names[v[i].first]);
        }

        return ans;
    }
};