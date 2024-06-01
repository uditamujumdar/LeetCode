class Solution {
public:
    void f(int ind, vector<int>&nums,vector<int>&output,vector<vector<int>>&ans){
        if(ind>=nums.size()){
            if(output.size()>1){
                ans.push_back(output);
            }
            return;
        }
        if(output.size()==0){
            output.push_back(nums[ind]);
            f(ind+1,nums,output,ans);
            output.pop_back();
        }
        else if(nums[ind]>=output.back()){
            output.push_back(nums[ind]);
            f(ind+1,nums,output,ans);
            output.pop_back();
        }
        f(ind+1,nums,output,ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int n=nums.size();
        f(0,nums,output,ans);
        sort(ans.begin(), ans.end());
        
        set<vector<int>>st;
        for(auto it: ans){
            st.insert(it);
        }
        vector<vector<int>>res;
        for(auto it: st){
            res.push_back(it);
        }
        return res;
    }
};