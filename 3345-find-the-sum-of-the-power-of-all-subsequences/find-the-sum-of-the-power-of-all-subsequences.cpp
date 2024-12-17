class Solution {
public:
int mod=1e9+7;
    int f(int x){
        int ans=1;
        while(x--){
            ans=(ans*2)%mod;
        }
        return ans;
    }

    int f(int ind, int sum, int cnt, int k, vector<int>&v, vector<vector<vector<int>>>&dp){
        if(sum>k){
            return 0;
        }
        if(sum==k){
            return f(v.size()-cnt);
        }
        if(ind>=v.size()){
            return 0;
        }
        if(dp[ind][sum][cnt]!=-1){
            return dp[ind][sum][cnt];
        }
        int pick=f(ind+1,sum+v[ind],cnt+1,k,v,dp);
        int notpick=f(ind+1,sum,cnt,k,v,dp);

        return dp[ind][sum][cnt]=(pick+notpick)%mod;
    }

    int sumOfPower(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(101, vector<vector<int>>(101, vector<int>(101,-1)));
        return f(0,0,0,k,nums,dp);
    }
};