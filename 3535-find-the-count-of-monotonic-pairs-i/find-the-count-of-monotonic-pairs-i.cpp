class Solution {
const int mod=1e9+7;//%mod
int dp[2001][51][51];
private:
    int solver(int prev1,int prev2,vector<int>& nums,int index)
    {
        if(index==nums.size())
        {
            return 1%mod;
        }
        
        if(dp[index][prev1][prev2]!=-1)
        {
           return dp[index][prev1][prev2]%mod;
        }
        long long pick=0;

        for(int i=prev1;i<=nums[index];i++)
        {
            int targ1=i;
            int targ2=nums[index]-i;
            if(targ2<=prev2)
            {
                pick+=solver(targ1,targ2,nums,index+1);
            }
        }
        return dp[index][prev1][prev2]=pick%mod;
    }
public:
    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solver(0,50,nums,0)%mod;
    }
};