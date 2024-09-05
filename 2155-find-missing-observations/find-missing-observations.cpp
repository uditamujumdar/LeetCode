class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=mean*(n+m);
        int curr=accumulate(rolls.begin(), rolls.end(), 0);

        int req=sum-curr;
        if(n*6<req || req<n){
            return {};
        }
        int rem=req%n;
        int x=req/n;
        
        vector<int>ans(n,x);
        for(int i=1;i<=rem;i++){
            ans[i]++;
        }
        return ans;
    }
};