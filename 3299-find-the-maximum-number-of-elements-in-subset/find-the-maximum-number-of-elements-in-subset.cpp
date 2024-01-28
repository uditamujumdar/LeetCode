class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }

       long long ans=mp[1];
        if(ans%2==0)ans--;
        
        for(auto it:mp)
        {
            if(it.first==1)continue;
            long long now=it.first;
            long long cnt=0;
            while(mp.find(now)!=mp.end() && mp[now]>=2)
            {
                cnt+=2;
                now=now*now;
            }
            if(mp.find(now)==mp.end())
            {
                cnt--;
            }
            else
            {
                cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};