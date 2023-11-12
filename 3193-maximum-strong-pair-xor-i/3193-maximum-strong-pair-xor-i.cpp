class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(abs(nums[i]-nums[j])<=min(nums[i], nums[j])){
                    int x=nums[i]^nums[j];
                    maxi=max(maxi, x);
                }
            }
        }
        return maxi;
    }
};