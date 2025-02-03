class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi1=INT_MIN, maxi2=INT_MIN, cnt1=0, cnt2=0;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                cnt1++;
                maxi1=max(maxi1, cnt1);
            }
            else{
                cnt1=0;
            }
            if(nums[i]>nums[i+1]){
                cnt2++;
                maxi2=max(maxi2, cnt2);
            }
            else{
                cnt2=0;
            }
        }
        if(maxi1==INT_MIN && maxi2==INT_MIN){
            return 1;
        }
        
        return max(maxi1, maxi2)+1;
    }
};