class Solution {
public:
    int f(int ind, vector<int>&st, vector<int>&dp){
        if(ind>=st.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=INT_MIN;

        ans=max(ans, st[ind]-f(ind+1,st,dp));

        if(ind+1<st.size()){
            ans=max(ans, st[ind]+st[ind+1]-f(ind+2,st,dp));
        }
        if(ind+2<st.size()){
            ans=max(ans, st[ind]+st[ind+1]+st[ind+2]-f(ind+3,st,dp));
        }

        return dp[ind]=ans;
    }

    string stoneGameIII(vector<int>& st) {
        int n=st.size();
        vector<int>dp(n+1, -1);
        // int total=accumulate(st.begin(), st.end(),0);
        int ans=f(0,st,dp);

        if(ans>0){
            return "Alice";
        }
        else if(ans<0){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};