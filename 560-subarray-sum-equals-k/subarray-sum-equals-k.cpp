class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>mp;
        int sum=0, ans=0;
        mp[sum]=1;

        for(auto it: nums){
            sum+=it;
            int tar=sum-k;
            if(mp.find(tar)!=mp.end()){
                ans+=mp[tar];
            }
            mp[sum]++;
        }
        return ans;
    }
};