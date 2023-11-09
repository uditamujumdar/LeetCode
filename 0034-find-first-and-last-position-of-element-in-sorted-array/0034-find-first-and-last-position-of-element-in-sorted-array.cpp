class Solution {
public:
    int lowerb(vector<int>& nums, int target, int n){
        int ans=n;
        int low=0, high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }

    int upperb(vector<int>& nums, int target, int n){
        int ans=n;
        int low=0, high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();

        int first=lowerb(nums, target, n);
        if(first==n || nums[first]!=target){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        ans.push_back(first);
        ans.push_back(upperb(nums, target, n)-1);
        return ans;
    }
};