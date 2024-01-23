class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=0;

        if(nums[0]>0){
            ans++;
        }
        int size=0;

        for(int i=0;i<n;i++){
            size++;
            if(size>nums[i]){
                if(i<n-1 && size<nums[i+1]){
                    ans++;
                }
                else if(i==n-1){
                    ans++;
                }
            }
        }
        return ans;
    }
};