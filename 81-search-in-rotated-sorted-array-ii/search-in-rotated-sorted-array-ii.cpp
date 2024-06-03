class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;

        while(i<=j){
            int mid=i+(j-i)/2;

            if(nums[mid]==target){
                return true;
            }
            if(nums[i]==nums[mid] && nums[j]==nums[mid]){
                i=i+1;
                j=j-1;
                continue;
            }

            //left sorted
            if(nums[i]<=nums[mid]){
                if(nums[i]<=target && nums[mid]>=target){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
            //right sorted
            else{
                if(nums[mid]<=target && nums[j]>=target){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
        }
        return false;
    }
};