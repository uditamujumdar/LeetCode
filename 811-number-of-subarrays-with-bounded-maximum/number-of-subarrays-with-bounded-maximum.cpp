class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i=0,j=0;
        int maxi=0;
        long long ans=0;

        while(j<nums.size()){
            if(nums[j]>=left&&nums[j]<=right){
                maxi=max(maxi, j-i+1);
            }
            else if(nums[j]>right){
                i=j+1;
                maxi=0;
            }
            else{
                maxi=max(maxi, 0);
            }
            ans+=maxi;
            j++;
        }        
        return ans;
    }
};