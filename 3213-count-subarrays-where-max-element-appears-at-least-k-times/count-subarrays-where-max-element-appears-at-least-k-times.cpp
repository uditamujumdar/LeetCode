class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(), nums.end());

        unordered_map<int,int>mp;
        int i=0, j=0;
        long long cnt=0;
        while(j<nums.size()){
            if(nums[j]==maxi){
                mp[nums[j]]++;
            }
            while(mp[maxi]>=k){
                cnt+=nums.size()-j;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};