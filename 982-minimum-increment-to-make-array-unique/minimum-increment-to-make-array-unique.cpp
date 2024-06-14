class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int cnt=0, maxi=INT_MIN;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]++;
                maxi=max(maxi, nums[i]);
            }
            else{
                cnt+=maxi-nums[i]+1;
                nums[i]=maxi+1;
                maxi=max(maxi, nums[i]);
                mp[nums[i]]++;
            }
        }
        return cnt;
    }
};