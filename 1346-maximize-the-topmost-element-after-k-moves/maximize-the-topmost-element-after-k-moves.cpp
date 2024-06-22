class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0){
            return nums[0];
        }
        if(n==1 && k&1){
            return -1;
        }
        int maxi=*max_element(nums.begin(), nums.end());
        if(k>n){
            return maxi;
        }
        else{
            int maxxi=-1;
            for(int i=0;i<k-1;i++){
                maxxi=max(maxxi, nums[i]);
            }
            if(nums[k]>maxxi){
                maxxi=nums[k];
            }
            return maxxi;
        }
    }
};