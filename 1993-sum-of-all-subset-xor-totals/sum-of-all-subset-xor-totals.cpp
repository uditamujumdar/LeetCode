class Solution {
public:
    void solve(vector<int>&nums,vector<int>output,vector<vector<int>>&ans,int index)
{
        if(index>=nums.size())
        {
            ans.push_back(output);
            return ;
        }

        solve(nums,output,ans,index+1);

        int element=nums[index];
        output.push_back(element);
        solve(nums,output,ans,index+1);
}

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        solve(nums,output,ans,index);

        int sum=0;
        int x=0;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                x^=ans[i][j];
            }
            sum+=x;
            x=0;
        }

        return sum;
    }
};