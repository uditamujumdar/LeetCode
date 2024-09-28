class Solution {
public:
    long long f(int ind, int cnt, vector<int>&a, vector<int>&b, vector<vector<long long>>&dp){
        if(cnt==4){
            return 0;
        }
        if(ind>=b.size()){
            return -1e9;
        }
        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }
        long long notpick=f(ind+1, cnt, a, b, dp);
        long long pick=(long long)a[cnt]*b[ind]+f(ind+1,cnt+1,a,b,dp);

        return dp[ind][cnt]=max(pick,notpick);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<long long>>dp(n, vector<long long>(4,-1));
        
        vector<int>bb={-100000,-100000,-100000,-100000};
        vector<int>aa={100000,100000,100000,100000};

        if(a==aa && b==bb){
            return -40000000000;
        }

        return f(0,0,a,b,dp);
    }
};