class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        int ans=0;
        int cnt=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]-nums[i+1]==nums[i+1]-nums[i+2]){
                cnt++;
                continue;
            }
            else{
                ans+=(cnt*(cnt+1)/2);
                cnt=0;
            }
        }
        ans+=(cnt*(cnt+1)/2);
        return ans;
    }
};