class Solution {
private:
int helper(int i,int n,vector<int>&days,vector<int>&costs,vector<int>&dp)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }

    //for 1day
    int oday=costs[0]+helper(i+1,n,days,costs,dp);

    // for 7days
    int next7days=days[i]+7-1;
    int indexfor7thday=i;

    while(indexfor7thday<n && days[indexfor7thday]<=next7days)
    {
        indexfor7thday++;
    }
    int sday=costs[1]+helper(indexfor7thday,n,days,costs,dp);

    //30days
    int next30thday=days[i]+30-1;
    int indexfor30thday=i;
    while(indexfor30thday<n && days[indexfor30thday]<=next30thday)
    {
        indexfor30thday++;
    }
    int tday=costs[2]+helper(indexfor30thday,n,days,costs,dp);

    return dp[i]=min(oday,min(sday,tday));
}

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i=0;
        int n=days.size();
        vector<int>dp(n+1,-1);
        return helper(i,n,days,costs,dp);
    }
};