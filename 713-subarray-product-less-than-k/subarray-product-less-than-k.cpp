class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1){
            return 0;
        }
        int prod=1;
        int i=0, j=0, ans=0;

        while(j<n){
            prod*=nums[j];
            while(prod>=k){
                prod/=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }

        return ans;
    }
};