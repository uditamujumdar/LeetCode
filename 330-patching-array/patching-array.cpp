class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans=0, ind=0;
        long long sum=1;

        while(sum<=n){
            if(ind<nums.size() && nums[ind]<=sum){
                sum+=nums[ind++];
            }
            else{
                sum+=sum;
                ans++;
            }
        }
        return ans;
    }
};