class Solution {
public:
    void f(int ind, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans){
        if(ind>=nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        f(ind+1, nums, v, ans);
        v.pop_back();
        while(ind+1<nums.size() && nums[ind]==nums[ind+1]){
            ind++;
        }
        f(ind+1, nums, v, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>v;

        f(0, nums, v, ans);

        return ans;
    }
};