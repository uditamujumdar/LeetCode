#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ll n=nums.size();
        ll sum=accumulate(nums.begin(),nums.end(),0ll);
        ll rem=sum%p;
        if(rem==0){
            return 0;
        }
        map<ll,ll>mp;
        mp[0]=-1;
        ll pref=0;
        ll mini=n;

        for(ll i=0;i<n;i++){
            pref+=nums[i];
            ll curr=pref%p;
            ll tar=(curr-rem+p)%p;

            if(mp.find(tar)!=mp.end()){
                mini=min(mini, i-mp[tar]);
            }
            mp[curr]=i;
        }
        if(mini==n){
            return -1;
        }
        return mini;
    }
};