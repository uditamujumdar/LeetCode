class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        sort(nums.begin(), nums.end());
        for(int i=n-1;i>=0;i--){
            if(nums[i]>0 && mp.find(0-nums[i])!=mp.end()){
                return nums[i];
            }
        }
        return -1;
    }
};