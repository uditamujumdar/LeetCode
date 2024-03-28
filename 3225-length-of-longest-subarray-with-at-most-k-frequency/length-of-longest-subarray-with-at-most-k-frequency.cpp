class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int i=0, j=0;
        unordered_map<int,int>mp;

        while(j<nums.size()){
            mp[nums[j]]++;

            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            maxi=max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};