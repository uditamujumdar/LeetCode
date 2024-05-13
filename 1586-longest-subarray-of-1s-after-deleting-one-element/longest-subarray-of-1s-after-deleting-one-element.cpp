class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=0;
        unordered_map<int,int>mp;

        int maxi=INT_MIN;

        while(j<n){
            mp[nums[j]]++;
            if(mp[0]==2){
                while(mp[0]==2){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            }
            maxi=max(maxi, j-i+1);
            j++;
        }

        return maxi-1;
    }
};