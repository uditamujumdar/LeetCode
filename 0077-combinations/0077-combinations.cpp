class Solution {
public:
    void f(int i, int n, int k, vector<int>& v, vector<vector<int>>& ans){
        if(k==0){
            ans.push_back(v);
            return;
        }

        for(int j=i;j<=n;j++){
            v.push_back(j);
            f(j+1, n, k-1, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>v;
        f(1, n, k, v, ans);
        return ans;
    }
};