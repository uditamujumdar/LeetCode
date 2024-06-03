class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int ans=INT_MAX;

        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[i]<=nums[mid]){
                ans=min(ans, nums[i]);
                i=mid+1;
            }
            else{
                ans=min(ans, nums[mid]);
                j=mid-1;
            }
        }
        return ans;
    }
};