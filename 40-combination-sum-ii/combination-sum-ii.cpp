class Solution {
public:
    void solve(int ind,vector<int>& cand, int tar,vector<int>& output,vector<vector<int>>&ans){
        if(tar==0){
            ans.push_back(output);
            return;
        }

        for(int i=ind;i<cand.size();i++){
            if(i>ind && cand[i]==cand[i-1]){
                continue;
            }
            if(cand[i]>tar){
                break;
            }
            output.push_back(cand[i]);
            solve(i+1,cand,tar-cand[i],output,ans);
            output.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, output, ans);

        return ans;
    }
};