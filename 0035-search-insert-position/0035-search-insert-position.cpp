class Solution {
public:
    int bs(vector<int>& nums, int key, int n){
        int s=0, e=n-1;
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==key){
                return mid;
            }
            else if(nums[mid]>key){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return s;
    }


    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        return bs(nums, target, n);
    }
};