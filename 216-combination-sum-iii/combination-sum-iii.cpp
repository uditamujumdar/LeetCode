class Solution {
public:
    void f(int ind, int k, int n, vector<vector<int>>& ans, vector<int>&v){
        if(n==0 && v.size()==k){
            ans.push_back(v);
            return;
        }

        for(int i=ind;i<=9;i++){
            if(i>n){
                break;
            }
            v.push_back(i);
            f(i+1,k,n-i,ans,v);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;

        f(1,k,n,ans,v);

        return ans;
    }
};