class Solution {
public:
    int f(int day, set<int>& st, vector<int>& c, vector<int>& dp){
        if(day>365){
            return 0;
        }
        if(dp[day]!=-1){
            return dp[day];
        }

        if(st.find(day)!=st.end()){
            int a=c[0]+f(day+1, st, c, dp);
            int b=c[1]+f(day+7, st, c, dp);
            int cc=c[2]+f(day+30, st, c, dp);
            dp[day]=min({a,b,cc});
        }
        else{
            dp[day]=f(day+1, st, c, dp);
        }

        return dp[day];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        set<int>st(days.begin(), days.end());
        vector<int>dp(366, -1);
        return f(1, st, costs, dp);
    }
};