class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long cnt=0;

        for(int i=0;i<=nums.size();i++){
            if(i<nums.size() && nums[i]==0){
                cnt++;
            }
            else{
                ans+=(cnt*(cnt+1)/2);
                cnt=0;
            }
        }
        return ans;
    }
};