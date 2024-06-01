class Solution {
private:
bool check(int prev,int index,int sign,vector<int>& nums)
{
    if(sign==-1)
    {
        return true;
    }
    if(nums[index]-nums[prev]>0 && sign==1)
    {
        return true;
    }
    if(nums[index]-nums[prev]<0 && sign==0)
    {
        return true;
    }
    return false;
}
private:
int solver(int index,int prev,vector<int>& nums,int sign,vector<vector<vector<int>>>&dp)
{
    if(index>=nums.size())
    {
        return 0;
    }
    if(dp[index][prev+1][sign+1]!=-1)
    {
        return dp[index][prev+1][sign+1];
    }
    int pick=0;
    if(prev==-1 || check(prev,index,sign,nums))
    {
        if(sign>=0)
        {
            if(sign==0)
            {
                pick=1+solver(index+1,index,nums,1,dp);
            }
            else
            {
                pick=1+solver(index+1,index,nums,0,dp);
            }
        }
        else if(prev==-1)
        {
            pick=1+solver(index+1,index,nums,sign,dp);
        }
        else
        {
            if(nums[index]-nums[prev]<0)
            {
                pick=1+solver(index+1,index,nums,1,dp);
            }
            else if(nums[index]-nums[prev]>0)
            {
                 pick=1+solver(index+1,index,nums,0,dp);
            }
        }
    }
    int notpick=solver(index+1,prev,nums,sign,dp);

    return dp[index][prev+1][sign+1]=max(notpick,pick);
}
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(3,-1)));
        return solver(0,-1,nums,-1,dp);
    }
};