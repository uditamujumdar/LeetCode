class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0, j=0;
        unordered_map<int,int>mp;

        int maxi=INT_MIN;

        while(j<n){
            mp[nums[j]]++;
            if(mp[0]>k){
                while(mp[0]>k){
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

        return maxi;
    }
};