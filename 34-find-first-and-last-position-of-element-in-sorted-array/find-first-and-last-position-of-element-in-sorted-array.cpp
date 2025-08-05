class Solution {
public:
    int lb(vector<int>& nums, int tar){
        int n=nums.size();
        int i=0, j=n-1;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==tar){
                ans=mid;
                j=mid-1;
            }
            else if(nums[mid]<tar){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }

    int ub(vector<int>& nums, int tar){
        int n=nums.size();
        int i=0, j=n-1;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==tar){
                ans=mid;
                i=mid+1;
            }
            else if(nums[mid]<tar){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=lb(nums, target);
        if(first==-1){
            return {-1,-1};
        }
        int last=ub(nums, target);
        return {first, last};
    }
};