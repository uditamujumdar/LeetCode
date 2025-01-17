class Solution {
public:    
    long long maxStrength(vector<int>& nums) {
        int n=nums.size();
        long long prod=1;
        int mini=INT_MIN, maxi=INT_MIN, neg=0;

        for(int i=0;i<n;i++){
            if(nums[i]){
                prod*=nums[i];
            }
            if(nums[i]<0){
                mini=max(mini, nums[i]);
                neg++;
            }
            maxi=max(maxi, nums[i]);
        }
        if(maxi==0 && neg<2){
            return 0;
        }
        if(maxi<0 && neg==1){
            return mini;
        }
        if(prod>0){
            return prod;
        }
        return prod/mini;
    }
};