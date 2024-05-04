class Solution {
public:
    void f(int ind, vector<int>&nums, vector<int>&output, vector<vector<int>>&ans, int n){
        if(ind==n){
            ans.push_back(output);
            return;
        }

        for(int i=ind;i<n;i++){
            swap(nums[i],nums[ind]);
            output.push_back(nums[ind]);
            f(ind+1,nums,output,ans,n);
            output.pop_back();
            swap(nums[i],nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int n=nums.size();
        f(0,nums,output,ans,n);

        return ans;
    }
};