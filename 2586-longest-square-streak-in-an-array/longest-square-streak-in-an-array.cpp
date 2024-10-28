class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {        
        map<long long,long long>mp;
        for(auto it:nums){
            mp[it]++;
        }

        long long maxi=0;

        for(auto it:mp){
            long long curr=(long long)it.first*(long long)it.first;
            long long cnt=1;
            while(mp.find(curr)!=mp.end()){
                cnt++;
                curr=curr*curr;
            }
            maxi=max(maxi,cnt);
        }
        return maxi<=1?-1:maxi;
    }
};