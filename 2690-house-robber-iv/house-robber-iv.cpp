class Solution {
public:
    bool f(vector<int>&nums, int k, int mid){
        // int cap=0;
        // for(int i=0;i<nums.size();i++){
        //     if(k==0){
        //         break;
        //     }
        //     if(nums[i]<=mid){
        //         cap++;
        //         i++;
        //     }
        // }
        // return cap==k;
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                k--;
                i+=2;
            }
            else{
                i++;
            }
            if(k==0){
                return true;
            }
        }
        return k==0;
    }

    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int i=*min_element(nums.begin(), nums.end());
        int j=*max_element(nums.begin(), nums.end());

        while(i<=j){
            int mid=i+(j-i)/2;
            bool flag=f(nums, k, mid);

            if(flag){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return i;
    }
};