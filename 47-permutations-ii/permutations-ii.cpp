class Solution {
public:
    void f(int ind,vector<int>& nums, vector<vector<int>>&ans, int n){
        if(ind>=nums.size()){
            if(find(ans.begin(), ans.end(), nums)==ans.end()){
                ans.push_back(nums);;
            }
            return;
        }

        for(int j=ind;j<nums.size();j++){
            swap(nums[ind], nums[j]);

            f(ind+1, nums, ans, n);

            swap(nums[ind], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        f(0,nums,ans,n);
        return ans;
    }
};