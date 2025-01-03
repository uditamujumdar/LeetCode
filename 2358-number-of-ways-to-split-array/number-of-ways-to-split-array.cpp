class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long total=accumulate(nums.begin(), nums.end(),(long long)0);
        long long sum=0;
        int ans=0;

        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            if(sum>=(total-sum)){
                ans++;
            }
        }
        return ans;
    }
};