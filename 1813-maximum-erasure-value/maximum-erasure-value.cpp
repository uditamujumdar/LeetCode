class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>mp;
        int i=0,j=0;
        int sum=0, ans=INT_MIN;

        while(j<nums.size()){
            sum+=nums[j];
            mp[nums[j]]++;

            while(mp[nums[j]]==2){
                sum-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            j++;
            ans=max(ans, sum);
        }

        return ans;
    }
};