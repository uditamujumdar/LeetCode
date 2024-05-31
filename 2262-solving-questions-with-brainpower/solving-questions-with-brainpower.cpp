class Solution {
public:
    long long f(long long ind, vector<vector<int>>& ques, vector<long long>& dp){
        if(ind>=ques.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        long long notpick=f(ind+1, ques, dp);

        long long pick=ques[ind][0]+f(ind+ques[ind][1]+1, ques, dp);

        return dp[ind]=max(pick,notpick);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        long long n=questions.size();
        vector<long long>dp(n+1, -1);
        return f(0, questions, dp);
    }
};