class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0, j=n-1;

        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]>target){
                j=mid-1;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
//I reach for you, but you're not there,
//all I feel is cold despair.